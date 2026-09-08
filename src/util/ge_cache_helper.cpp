/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ge_cache_helper.h"
#include "ge_system_properties.h"

namespace OHOS::Rosen {

#ifdef GE_OHOS
int GECacheHelper::SDFCacheSystemFlag_ = OHOS::system::GetIntParameter("persist.sys.graphic.effect.enablesdfcache", -1);
#else
int GECacheHelper::SDFCacheSystemFlag_ = -1;
#endif

bool GECacheHelper::IsSDFCacheEnabled(bool defaultValue)
{
    // SDFCacheSystemFlag_ < 0, keep the defaultValue;
    // SDFCacheSystemFlag_ = 0，force false;
    // SDFCacheSystemFlag_ > 0，force true;
    if (SDFCacheSystemFlag_ < 0) {
        return defaultValue;
    }
    return SDFCacheSystemFlag_ > 0;
}
} // OHOS::Rosen