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
            uint8_t  EncScheme;
            uint8_t  IVLength;
            uint8_t  KeyIdLength;
            uint16_t SubSampleLength;
            uint32_t PatternEncBlocks;
            uint32_t PatternClearBlocks;
            uint8_t  IV[24];
            uint8_t  KeyId[17];
        };
        struct Administration {
            uint32_t Status;
            uint16_t SampleLength;
            SampleInfo Samples[32];
            CDMi::SubSampleInfo SubSamples[320];
            uint16_t StreamHeight;
            uint16_t StreamWidth;
            uint8_t  StreamType;
        };

    private:
        void SetIV(SampleInfo& sampleInfo, const uint8_t ivDataLength, const uint8_t ivData[])
        {
            VERIFY(ivDataLength <= sizeof(SampleInfo::IV));
            sampleInfo.IVLength = (ivDataLength > sizeof(SampleInfo::IV) ? sizeof(SampleInfo::IV) : ivDataLength);
            ::memcpy(sampleInfo.IV, ivData, sampleInfo.IVLength);
            if (sampleInfo.IVLength < sizeof(SampleInfo::IV)) {
                ::memset(&(sampleInfo.IV[sampleInfo.IVLength]), 0, (sizeof(SampleInfo::IV) - sampleInfo.IVLength));
            }
        }
        const uint8_t* IVKey(const SampleInfo& sampleInfo) const
        {
            return (&sampleInfo.IV[0]);
        }
        uint8_t IVKeyLength(const SampleInfo& sampleInfo) const
        {
            return (sampleInfo.IVLength);
        }
        void SetKeyId(SampleInfo& sampleInfo, const uint8_t length, const uint8_t buffer[])
        {
            VERIFY(length <= sizeof(SampleInfo::KeyId));
            sampleInfo.KeyId[0] = (length <= sizeof(SampleInfo::KeyId) ? length : sizeof(SampleInfo::KeyId));
            if (length != 0) {
                ::memcpy(&(sampleInfo.KeyId[1]), buffer, sampleInfo.KeyId[0]);
            }
        }
        const uint8_t* KeyId(const SampleInfo& sampleInfo, uint8_t& length) const
        {
            length = sampleInfo.KeyId[0];
            VERIFY(length <= 16);
            return (length > 0 ? &sampleInfo.KeyId[1] : nullptr);
        }
        void SetEncScheme(SampleInfo& sampleInfo, const uint8_t encScheme)
        {
            sampleInfo.EncScheme = encScheme;
        }
        uint8_t EncScheme(const SampleInfo& sampleInfo) const
        {
            return sampleInfo.EncScheme;
        }
        void SetEncPattern(SampleInfo& sampleInfo, const uint32_t encBlocks, const uint32_t clearBlocks)
        {
            sampleInfo.PatternEncBlocks = encBlocks;
            sampleInfo.PatternClearBlocks = clearBlocks;
        }
        void EncPattern(const SampleInfo& sampleInfo, uint32_t& encBlocks, uint32_t& clearBlocks) const
        {
            encBlocks = sampleInfo.PatternEncBlocks;
            clearBlocks = sampleInfo.PatternClearBlocks;
        }
        uint16_t SubSampleLength(const SampleInfo& sampleInfo) const
        {
            return (sampleInfo.SubSampleLength);
        }
        void SetSubSampleLength(SampleInfo& sampleInfo, const uint16_t length)
        {
            sampleInfo.SubSampleLength = std::min(static_cast<uint16_t>(sizeof(Administration::SubSamples)/sizeof(CDMi::SubSampleInfo)), length);
        }

        void SetSubSamples(const uint16_t startIdx, const uint16_t length, const CDMi::SubSampleInfo subSampleInfo[])
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            VERIFY(sizeof(Administration::SubSamples)/sizeof(CDMi::SubSampleInfo) >= (startIdx + length));
            for(uint16_t index = 0; index < length; index++) {
                admin->SubSamples[index + startIdx].encrypted_bytes = subSampleInfo[index].encrypted_bytes;
                admin->SubSamples[index + startIdx].clear_bytes = subSampleInfo[index].clear_bytes;
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
            admin->SampleLength = 0;
            admin->StreamHeight = 0;
            admin->StreamWidth = 0;
            admin->StreamType = 0;
        }
        void Status(uint32_t status)
        {
            reinterpret_cast<Administration*>(AdministrationBuffer())->Status = status;
        }
        uint32_t Status() const
        {
            return (reinterpret_cast<const Administration*>(AdministrationBuffer())->Status);
        }
        uint16_t SampleLength() const
        {
            const Administration* admin = reinterpret_cast<const Administration*>(AdministrationBuffer());
            return (admin->SampleLength);
        }
        void Samples(CDMi::SampleInfo *samplesInfo, const uint16_t length) const
        {
            const Administration* admin = reinterpret_cast<const Administration*>(AdministrationBuffer());
            VERIFY(admin->SampleLength >= length);
            for(uint16_t index = 0, subSampleIdx = 0; index < length; index++) {
                samplesInfo[index].ivLength = IVKeyLength(admin->Samples[index]);
                samplesInfo[index].iv = const_cast<uint8_t *>(IVKey(admin->Samples[index]));
                samplesInfo[index].keyId = const_cast<uint8_t *>(KeyId(admin->Samples[index], samplesInfo[index].keyIdLength));
                samplesInfo[index].scheme = static_cast<CDMi::EncryptionScheme>(EncScheme(admin->Samples[index]));
                EncPattern(admin->Samples[index], samplesInfo[index].pattern.encrypted_blocks, samplesInfo[index].pattern.clear_blocks);
                samplesInfo[index].subSample = const_cast<CDMi::SubSampleInfo *>(&(admin->SubSamples[subSampleIdx]));
                samplesInfo[index].subSampleCount = SubSampleLength(admin->Samples[index]);
                subSampleIdx += samplesInfo[index].subSampleCount;
            }
        }
        void SetSamples(const uint16_t length, const CDMi::SampleInfo samplesInfo[])
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            VERIFY(sizeof(Administration::Samples)/sizeof(SampleInfo) >= length);
            admin->SampleLength = std::min(static_cast<uint16_t>(sizeof(Administration::Samples)/sizeof(SampleInfo)), length);
            for(uint16_t index = 0, subSampleIdx = 0; index < admin->SampleLength; index++) {
                SetIV(admin->Samples[index], samplesInfo[index].ivLength, samplesInfo[index].iv);
                SetKeyId(admin->Samples[index], samplesInfo[index].keyIdLength, samplesInfo[index].keyId);
                SetEncScheme(admin->Samples[index], static_cast<uint8_t>(samplesInfo[index].scheme));
                SetEncPattern(admin->Samples[index], samplesInfo[index].pattern.encrypted_blocks, samplesInfo[index].pattern.clear_blocks);
                SetSubSampleLength(admin->Samples[index], samplesInfo[index].subSampleCount);
                SetSubSamples(subSampleIdx, samplesInfo[index].subSampleCount, samplesInfo[index].subSample);
                subSampleIdx += samplesInfo[index].subSampleCount;
            }
        }
        void SetMediaProperties(const uint16_t height, const uint16_t width, const uint8_t type)
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            admin->StreamHeight = height;
            admin->StreamWidth = width;
            admin->StreamType = type;
        }
        void MediaProperties(uint16_t& height, uint16_t& width, uint8_t& type)
        {
            Administration* admin = reinterpret_cast<Administration*>(AdministrationBuffer());
            height = admin->StreamHeight;
            width = admin->StreamWidth;
            type = admin->StreamType;
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
