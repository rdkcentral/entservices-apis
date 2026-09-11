/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"
#include "IDRM.h"

namespace WPEFramework {

namespace Exchange {

    // This interface gives direct access to a OpenCDMi server instance, running as a plugin in the framework.
    struct EXTERNAL IContentDecryption : virtual public Core::IUnknown {
        enum { ID = ID_CONTENTDECRYPTION };

        virtual uint32_t Initialize(PluginHost::IShell* service) = 0;
        virtual void Deinitialize(PluginHost::IShell* service) = 0;
        virtual uint32_t Reset() = 0;
        virtual RPC::IStringIterator* Systems() const = 0;
        virtual RPC::IStringIterator* Designators(const string& keySystem) const = 0;
        virtual RPC::IStringIterator* Sessions(const string& keySystem) const = 0;

        enum Status : uint8_t {
            BUSY,
            SUCCESS,
            FAILED
        };

        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {

            enum {ID = ID_CONTENTDECRYPTION_NOTIFICATION};

            /* @brief initialization status. */
            virtual void initializationStatus(const std::string& drm,
                                              const Status status) = 0;
        };

        virtual uint32_t Register(IContentDecryption::INotification* notification VARIABLE_IS_NOT_USED) { return Core::ERROR_NOT_SUPPORTED; };
        virtual uint32_t Unregister(IContentDecryption::INotification* notification VARIABLE_IS_NOT_USED) { return Core::ERROR_NOT_SUPPORTED; };
    };

    class DataExchange : public Core::SharedBuffer {
    private:
        struct SampleInfo {
            uint8_t  encScheme;
            uint8_t  ivLength;
            uint8_t  keyIdLength;
            uint16_t subSampleLength;
            uint32_t patternEncBlocks;
            uint32_t patternClearBlocks;
            uint8_t  iv[24];
            uint8_t  keyId[17];
        };
        struct Administration {
            uint32_t status;
            uint16_t sampleLength;
            SampleInfo samples[32];
            CDMi::SubSampleInfo subSamples[320];
            uint16_t streamHeight;
            uint16_t streamWidth;
            uint8_t  streamType;
        };

    private:
        void SetIV(SampleInfo& sampleInfo, const uint8_t ivDataLength, const uint8_t ivData[])
        {
            VERIFY(ivDataLength <= sizeof(SampleInfo::iv));
            sampleInfo.ivLength = (ivDataLength > sizeof(SampleInfo::iv) ? sizeof(SampleInfo::iv) : ivDataLength);
            ::memcpy(sampleInfo.iv, ivData, sampleInfo.ivLength);
            if (sampleInfo.ivLength < sizeof(SampleInfo::iv)) {
                ::memset(&(sampleInfo.iv[sampleInfo.ivLength]), 0, (sizeof(SampleInfo::iv) - sampleInfo.ivLength));
            }
        }
        const uint8_t* IVKey(const SampleInfo& sampleInfo) const
        {
            return (&sampleInfo.iv[0]);
        }
        uint8_t IVKeyLength(const SampleInfo& sampleInfo) const
        {
            return (sampleInfo.ivLength);
        }
        void SetKeyId(SampleInfo& sampleInfo, const uint8_t length, const uint8_t buffer[])
        {
            VERIFY(length <= 16);
            sampleInfo.keyId[0] = (length <= 16 ? length : 16);
            if (length != 0) {
                ::memcpy(&(sampleInfo.keyId[1]), buffer, sampleInfo.keyId[0]);
            }
        }
        const uint8_t* KeyId(const SampleInfo& sampleInfo, uint8_t& length) const
        {
            length = sampleInfo.keyId[0];
            VERIFY(length <= 16);
            return (length > 0 ? &sampleInfo.keyId[1] : nullptr);
        }
        void SetEncScheme(SampleInfo& sampleInfo, const uint8_t encScheme)
        {
            sampleInfo.encScheme = encScheme;
        }
        uint8_t EncScheme(const SampleInfo& sampleInfo) const
        {
            return sampleInfo.encScheme;
        }
        void SetEncPattern(SampleInfo& sampleInfo, const uint32_t encBlocks, const uint32_t clearBlocks)
        {
            sampleInfo.patternEncBlocks = encBlocks;
            sampleInfo.patternClearBlocks = clearBlocks;
        }
        void EncPattern(const SampleInfo& sampleInfo, uint32_t& encBlocks, uint32_t& clearBlocks) const
        {
            encBlocks = sampleInfo.patternEncBlocks;
            clearBlocks = sampleInfo.patternClearBlocks;
        }
        uint16_t SubSampleLength(const SampleInfo& sampleInfo) const
        {
            return (sampleInfo.subSampleLength);
        }
        void SetSubSampleLength(SampleInfo& sampleInfo, const uint16_t length)
        {
            sampleInfo.subSampleLength = std::min(static_cast<uint16_t>(sizeof(Administration::subSamples)/sizeof(CDMi::SubSampleInfo)), length);
        }

        void SetSubSamples(const uint16_t startIdx, const uint16_t length, const CDMi::SubSampleInfo subSampleInfo[])
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            VERIFY(sizeof(Administration::subSamples)/sizeof(CDMi::SubSampleInfo) >= (startIdx + length));
            for(uint16_t index = 0; index < length; index++) {
                admin->subSamples[index + startIdx].encrypted_bytes = subSampleInfo[index].encrypted_bytes;
                admin->subSamples[index + startIdx].clear_bytes = subSampleInfo[index].clear_bytes;
            }
        }

        void InitWithLast15(SampleInfo& sampleInfo, bool initWithLast15)
        {
            if (initWithLast15 == true) {
                sampleInfo.ivLength |= 0x80;
            } else {
                sampleInfo.ivLength &= (~0x80);
            }
        }

    public:
        DataExchange() = delete;
        DataExchange(const DataExchange&) = delete;
        DataExchange& operator=(const DataExchange&) = delete;

        DataExchange(const string& name)
            : Core::SharedBuffer(name.c_str())
        {
        }
        DataExchange(const string& name, const uint32_t bufferSize)
            : Core::SharedBuffer(name.c_str(), 
                Core::File::USER_READ    |
                Core::File::USER_WRITE   |
                Core::File::USER_EXECUTE |
                Core::File::GROUP_READ   |
                Core::File::GROUP_WRITE  |
                Core::File::OTHERS_READ  |
                Core::File::OTHERS_WRITE,
                bufferSize,
                sizeof(Administration))
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            // Clear the administration space before using it.
            ::memset(admin, 0, sizeof(Administration));
        }
        ~DataExchange() = default;

    public:
        void Clear() 
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            admin->sampleLength = 0;
            admin->streamHeight = 0;
            admin->streamWidth = 0;
            admin->streamType = 0;
        }
        void Status(uint32_t status)
        {
            reinterpret_cast<Administration*>(AdministrationBuffer())->status = status;
        }
        uint32_t Status() const
        {
            return (reinterpret_cast<const Administration*>(AdministrationBuffer())->status);
        }
        uint16_t SampleLength() const
        {
            const Administration* admin = reinterpret_cast<const Administration*>(AdministrationBuffer());
            return (admin->sampleLength);
        }
        void Samples(CDMi::SampleInfo *samplesInfo, const uint16_t length) const
        {
            const Administration* admin = reinterpret_cast<const Administration*>(AdministrationBuffer());
            VERIFY(admin->sampleLength >= length);
            uint16_t retLength = (length > admin->sampleLength) ? admin->sampleLength : length;
            for(uint16_t index = 0, subSampleIdx = 0; index < retLength; index++) {
                samplesInfo[index].ivLength = IVKeyLength(admin->samples[index]);
                samplesInfo[index].iv = const_cast<uint8_t *>(IVKey(admin->samples[index]));
                samplesInfo[index].keyId = const_cast<uint8_t *>(KeyId(admin->samples[index], samplesInfo[index].keyIdLength));
                samplesInfo[index].scheme = static_cast<CDMi::EncryptionScheme>(EncScheme(admin->samples[index]));
                EncPattern(admin->samples[index], samplesInfo[index].pattern.encrypted_blocks, samplesInfo[index].pattern.clear_blocks);
                samplesInfo[index].subSample = const_cast<CDMi::SubSampleInfo *>(&(admin->subSamples[subSampleIdx]));
                samplesInfo[index].subSampleCount = SubSampleLength(admin->samples[index]);
                subSampleIdx += samplesInfo[index].subSampleCount;
            }
        }
        void SetSamples(const uint16_t length, const CDMi::SampleInfo samplesInfo[], bool initWithLast15)
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            VERIFY(sizeof(Administration::samples)/sizeof(SampleInfo) >= length);
            admin->sampleLength = std::min(static_cast<uint16_t>(sizeof(Administration::samples)/sizeof(SampleInfo)), length);
            for(uint16_t index = 0, subSampleIdx = 0; index < admin->sampleLength; index++) {
                SetIV(admin->samples[index], samplesInfo[index].ivLength, samplesInfo[index].iv);
                SetKeyId(admin->samples[index], samplesInfo[index].keyIdLength, samplesInfo[index].keyId);
                SetEncScheme(admin->samples[index], static_cast<uint8_t>(samplesInfo[index].scheme));
                SetEncPattern(admin->samples[index], samplesInfo[index].pattern.encrypted_blocks, samplesInfo[index].pattern.clear_blocks);
                SetSubSampleLength(admin->samples[index], samplesInfo[index].subSampleCount);
                SetSubSamples(subSampleIdx, samplesInfo[index].subSampleCount, samplesInfo[index].subSample);
                subSampleIdx += samplesInfo[index].subSampleCount;

                InitWithLast15(admin->samples[index], initWithLast15);
            }
        }
        void SetMediaProperties(const uint16_t height, const uint16_t width, const uint8_t type)
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            admin->streamHeight = height;
            admin->streamWidth = width;
            admin->streamType = type;
        }
        void MediaProperties(uint16_t& height, uint16_t& width, uint8_t& type)
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            height = admin->streamHeight;
            width = admin->streamWidth;
            type = admin->streamType;
        }
        void Write(const uint32_t length, const uint8_t* data)
        {
            if (Core::SharedBuffer::Size(length) == true) {
                SetBuffer(0, length, data);
            }
        }
        void Read(const uint32_t length, uint8_t* data) const
        {
            GetBuffer(0, length, data);
        }
    };
}
}
