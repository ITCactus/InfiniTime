#pragma once
#include <host/ble_gap.h>

namespace Pinetime {
  namespace System {
    class SystemTask;
  }
  namespace Controllers {
    class BatteryInformationService {
      public:
        BatteryInformationService();
        void Init();

        int
        OnBatteryServiceRequested(uint16_t connectionHandle, uint16_t attributeHandle, ble_gatt_access_ctxt *context);

      private:
        static constexpr uint16_t batteryInformationServiceId {0x180F};
        static constexpr uint16_t batteryLevelId {0x2A19};

        static constexpr ble_uuid16_t batteryInformationServiceUuid {
                .u {.type = BLE_UUID_TYPE_16},
                .value = batteryInformationServiceId
        };

        static constexpr ble_uuid16_t batteryLevelUuid {
                .u {.type = BLE_UUID_TYPE_16},
                .value = batteryLevelId
        };

        struct ble_gatt_chr_def characteristicDefinition[3];
        struct ble_gatt_svc_def serviceDefinition[2];

        uint16_t batteryLevelHandle;

    };
  }
}

