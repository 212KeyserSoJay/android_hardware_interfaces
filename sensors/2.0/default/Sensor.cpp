/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Sensor.h"

namespace android {
namespace hardware {
namespace sensors {
namespace V2_0 {
namespace implementation {

Sensor::Sensor() : mIsEnabled(false), mSamplingPeriodNs(0) {}

const SensorInfo& Sensor::getSensorInfo() const {
    return mSensorInfo;
}

bool Sensor::batch(int32_t samplingPeriodNs) {
    bool success = true;
    if (samplingPeriodNs >= mSensorInfo.minDelay * 1000 &&
        samplingPeriodNs <= mSensorInfo.maxDelay * 1000) {
        mSamplingPeriodNs = samplingPeriodNs;
    } else {
        success = false;
    }
    return success;
}

void Sensor::activate(bool enable) {
    mIsEnabled = enable;
}

}  // namespace implementation
}  // namespace V2_0
}  // namespace sensors
}  // namespace hardware
}  // namespace android