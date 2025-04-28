/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 RDK Management
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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {
/* @json 1.0.0 @text:keep */
struct EXTERNAL IUSBMassStorage : virtual public Core::IUnknown
{
    enum { ID = ID_USB_MASS_STORAGE };

    enum USBStorageMountFlags : uint8_t
    {
        READ_ONLY     = 1  /* @text READ_ONLY */,
        READ_WRITE    = 2  /* @text READ_WRITE */
    };

    enum USBStorageFileSystem : uint8_t
    {
        UNKNOWN         = 0  /* @text UNKNOWN file system */,
        MSDOS        = 1  /* @text MSDOS file system driver  */,
        VFAT         = 2  /* @text VFAT file system driver  */,
        EXT4         = 3  /* @text EXT4 file system */,
        EXFAT        = 4  /* @text EXFAT file system */
    };

    struct USBStorageDeviceInfo
    {
        string   devicePath     /* @brief Device path in the file system (sysfs) */;
        string   deviceName     /* @brief Device name identifying the device */;
    };

    using IUSBStorageDeviceInfoIterator = RPC::IIteratorType<USBStorageDeviceInfo, ID_USB_MASS_STORAGE_DEVICE_INFO_ITERATOR>;

    struct USBStorageMountInfo
    {
        string                  partitionName  /* @brief name of the partition */;
        USBStorageMountFlags    mountFlags     /* @brief Mount flags used for mounting the device / partition */;
        string                  mountPath      /* @brief path at which the partition is mounted on */;
        USBStorageFileSystem    fileSystem     /* @brief file system of the partition */;
    };

    using IUSBStorageMountInfoIterator = RPC::IIteratorType<USBStorageMountInfo, ID_USB_MASS_STORAGE_MOUNT_INFO_ITERATOR>;

    struct USBStoragePartitionInfo
    {
        USBStorageFileSystem    fileSystem      /* file system of the partition */;
        uint32_t                size            /* total size of the partition in MB */;
        uint64_t                startSector     /* start sector of the partition */;
        uint64_t                numSectors      /* number of sectors in the partition */;
        uint32_t                sectorSize      /* size of the sector in the partition in bytes */;
        uint32_t                totalSpace      /* total space of the partition in MB */;
        uint32_t                usedSpace       /* used space in the partition in MB */;
        uint32_t                availableSpace /* available space in the partition in MB */;
    };


    struct EXTERNAL INotification : virtual public Core::IUnknown
    {
        enum { ID = ID_USB_MASS_STORAGE_NOTIFICATION };

        // @brief Device Mounted notification
        // @@iterator
        // @text onDeviceMounted
        // @param deviceInfo: name and device path of the mounted device.
        // @param mountPoints: List of mountpoints information for the device mounted.
        virtual void OnDeviceMounted(const USBStorageDeviceInfo &deviceInfo /* @in */, IUSBStorageMountInfoIterator* const mountPoints /* @in */) {};

        // @brief Device Unmounted notification
        // @@iterator
        // @text onDeviceUnMounted
        // @param deviceInfo: name and device path of the mounted device.
        // @param mountPoints: List of mountpoints information for the device unmounted.
        virtual void OnDeviceUnmounted(const USBStorageDeviceInfo &deviceInfo /* @in */, IUSBStorageMountInfoIterator* const mountPoints /* @in */) {};
    };

    // @json:omit
    virtual Core::hresult Register(Exchange::IUSBMassStorage::INotification *notification) = 0;
    // @json:omit
    virtual Core::hresult Unregister(Exchange::IUSBMassStorage::INotification *notification) = 0;

    /** Get list of devices that are currently mounted in the system */
    // @text getDeviceList
    // @brief Get list of devices that are currently mounted in the system
    // @param deviceInfo: Device info for devices that are currently mounted.
    virtual Core::hresult GetDeviceList(IUSBStorageDeviceInfoIterator*& deviceInfo /* @out */ ) const = 0;

    /** Get mount points information for a specified device.*/
    // @text getMountPoints
    // @brief Get mount points information for a specified device
    // @param deviceName: name of the device for which mount points are to be retrieved
    // @param mountPoints: List of mountpoints information for a given device.
    virtual Core::hresult GetMountPoints(const string &deviceName /* @in */, IUSBStorageMountInfoIterator*& mountPoints /* @out */ ) const = 0;

    /** Get partition information for a given partition.*/
    // @text getPartitionInfo
    // @brief Get partition information for a given partition
    // @param mountPath : mount path of the partition for which more info is required
    // @param partitionInfo: partition info details
    virtual Core::hresult GetPartitionInfo(const string &mountPath /* @in @text mountPath */, USBStoragePartitionInfo &partitionInfo /* @out */) const = 0;

};
} // namespace Exchange
} // namespace WPEFramework
