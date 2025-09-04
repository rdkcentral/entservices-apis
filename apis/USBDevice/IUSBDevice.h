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
 * https://urldefense.com/v3/__http://www.apache.org/licenses/LICENSE-2.0__;!!CQl3mcHX2A!AIsdoV9RmJiZ-kCiJ9jXDf3DLnAMym8wdLb8gsUImxAgKS0zfqaIaTfDxhK13YAXmnDoeM2e2EwiMuldtIvjMfPJ1qBfEQpl$ 
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"
#include "entservices_errorcodes.h"

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {
/* @json 1.0.0 @text:keep */
struct EXTERNAL IUSBDevice : virtual public Core::IUnknown {
    enum { ID = ID_USB_DEVICE };

    struct USBDevice {
        uint8_t  deviceClass    /* @brief USB class of the device as per USB specificiation */ ;
        uint8_t  deviceSubclass /* @brief USB sub class of the device as per USB specificiation */;
        string   deviceName     /* @brief Name of the USB device */;
        string   devicePath     /* @brief the path to be used for the USB device ex: /dev/sdX */;
    };
    using IUSBDeviceIterator = RPC::IIteratorType<USBDevice, ID_USB_DEVICE_ITERATOR>;
    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = ID_USB_DEVICE_NOTIFICATION };

    // @brief Device Plugged in notification
    // @text onDevicePluggedIn
    // @param USBDevice: USB information of the plugged in device
    virtual void OnDevicePluggedIn(const USBDevice &device) {};

    // @brief Device Plugged out notification
    // @text onDevicePluggedOut
    // @param USBDevice: USB information of the plugged in device
    virtual void OnDevicePluggedOut(const USBDevice &device) {};

    };

    /** Register notification interface */
    virtual Core::hresult Register(Exchange::IUSBDevice::INotification *notification) = 0;
    /** Unregister notification interface */
    virtual Core::hresult Unregister(Exchange::IUSBDevice::INotification *notification) = 0;

    struct USBProductInfo {
        uint16_t languageId    /* @brief language id present on the device */;
        string   serialNumber  /* @brief unicode string representing the serial number of the device */;
        string   manufacturer  /* @brief unicode string representing the manufacturer of the device */;
        string   product       /* @brief unicode string representing the product */;
    };
    using IUSBProductInfoIterator = RPC::IIteratorType<USBProductInfo, ID_USB_PRODUCT_INFO_ITERATOR>;

    enum USBDeviceSpeed : uint8_t {
        DEVICE_SPEED_LOW     = 1  /* @text Low */,
        DEVICE_SPEED_FULL    = 2  /* @text Full */,
        DEVICE_SPEED_HIGH    = 3  /* @text High */,
        DEVICE_SPEED_SUPER   = 4  /* @text Super */
    };

    enum USBDeviceFlags : uint8_t {
        DEVICE_FLAGS_DRIVER_AVAILABLE = 1  /* @text AVAILABLE */,
        DEVICE_FLAGS_SWITCHABLE       = 2  /* @text SWITCHABLE */
    };

    enum USBDeviceStatus : uint8_t {
        DEVICE_STATUS_ACTIVE                = 0x01  /* @text Active */,
        DEVICE_STATUS_NO_DEVICE_CONNECTED   = 0x02  /* @text NoDeviceConnected*/,
        DEVICE_STATUS_SELF_POWERED          = 0x04  /* @text SelfPowered */
    };

    struct USBDeviceInfo {
        uint32_t         parentId       /* @brief Parent Node ID of the device */;
        uint8_t          deviceStatus   /* @bitmask current device status */;
        uint8_t          deviceLevel    /* @brief device level */;
        uint8_t          portNumber     /* @brief port number of USB on which the device is attached */;
        uint16_t         vendorId       /* @brief Vendor ID of the device */;
        uint16_t         productId      /* @brief Product ID of the device */;
        uint8_t          protocol       /* @brief Protocol supported by the device */;
        string           serialNumber   /* @brief Serial number of the device */;
        USBDevice	     device     	/* @brief Basic device information included */;
        USBDeviceFlags   flags          /* @brief Flags of the device */;
        uint32_t         features       /* @brief Features supported by the device - reserved */;
        USBDeviceSpeed   busSpeed       /* @brief Speed of the device */;
        uint8_t          numLanguageIds /* @brief number of language ids present on the device */;
        USBProductInfo productInfo1;
        USBProductInfo productInfo2;
        USBProductInfo productInfo3;
        USBProductInfo productInfo4;
    };
    using IUSBDeviceInfoIterator = RPC::IIteratorType<USBDeviceInfo, ID_USB_DEVICE_INFO_ITERATOR>;

    /** Gets the device information of the connected USB Devices.*/
    // @text getDeviceList
    // @brief Get the basic information about list of devices connected with the system.
    // @param devices : List of USB devices along with basic info.
    virtual Core::hresult GetDeviceList(IUSBDeviceIterator*& devices /* @out */ ) const = 0;

    /** Gets detailed device information for the given device name */
    // @text getDeviceInfo
    // @brief Get the extended USB device information for the provided device name
    // @param deviceName: device name
    // @param deviceInfo: Detailed device information
    virtual Core::hresult GetDeviceInfo(const string &deviceName /* @in @text deviceName */, USBDeviceInfo& deviceInfo /* @out */) const = 0;

    /** Binds the respective driver for the device */
    // @text bindDriver
    // @brief Bind the respective driver for the device
    // @param deviceName: Name of the device
    virtual Core::hresult BindDriver(const string &deviceName /* @in @text deviceName */) const = 0;

    /** Unbinds the respective driver for the device */
    // @text unbindDriver
    // @brief Unbind the respective driver for the device
    // @param deviceName: Name of the device
    virtual Core::hresult UnbindDriver(const string &deviceName /* @in @text deviceName */) const = 0;
};

} // namespace Exchange
} // namespace WPEFramework
