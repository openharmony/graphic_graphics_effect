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

#include <gtest/gtest.h>
#include "ge_cache_helper.h"
#ifdef GE_OHOS
#include <parameter.h>
#include <parameters.h>
#include "param/sys_param.h"
#include "utils/system_properties.h"
#endif

using namespace testing;
using namespace testing::ext;

namespace OHOS {
namespace Rosen {

class GECacheHelperTest : public testing::Test {
public:
    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    const std::string enableSDFTag_ = "persist.sys.graphic.effect.enablesdfcache";
    const std::string keepDefaultValue_ = "-1";
};

void GECacheHelperTest::SetUpTestCase(void) {}
void GECacheHelperTest::TearDownTestCase(void) {}
void GECacheHelperTest::SetUp()
{
    system::SetParameter(enableSDFTag_.c_str(), keepDefaultValue_.c_str());
}

void GECacheHelperTest::TearDown()
{
    system::SetParameter(enableSDFTag_.c_str(), keepDefaultValue_.c_str());
}

/**
 * @tc.name: IsSDFCacheEnabled_NegativeFlagWithTrueDefault
 * @tc.desc: Verify IsSDFCacheEnabled returns defaultValue(true) when SDFCacheSystemFlag < 0
 * @tc.type: FUNC
 */
HWTEST_F(GECacheHelperTest, IsSDFCacheEnabled_NegativeFlagWithTrueDefault, TestSize.Level1)
{
    int originalFlag = GECacheHelper::SDFCacheSystemFlag_;
    GECacheHelper::SDFCacheSystemFlag_ = -1;
    EXPECT_TRUE(GECacheHelper::IsSDFCacheEnabled(true));
    GECacheHelper::SDFCacheSystemFlag_ = originalFlag;
}

/**
 * @tc.name: IsSDFCacheEnabled_NegativeFlagWithFalseDefault
 * @tc.desc: Verify IsSDFCacheEnabled returns defaultValue(false) when SDFCacheSystemFlag_ < 0
 * @tc.type: FUNC
 */
HWTEST_F(GECacheHelperTest, IsSDFCacheEnabled_NegativeFlagWithFalseDefault, TestSize.Level1)
{
    int originalFlag = GECacheHelper::SDFCacheSystemFlag_;
    GECacheHelper::SDFCacheSystemFlag_ = -1;
    EXPECT_FALSE(GECacheHelper::IsSDFCacheEnabled(false));
    GECacheHelper::SDFCacheSystemFlag_ = originalFlag;
}

/**
 * @tc.name: IsSDFCacheEnabled_ZeroFlagWithTrueDefault
 * @tc.desc: Verify IsSDFCacheEnabled forces false when SDFCacheSystemFlag_ == 0 and defaultValue is true
 * @tc.type: FUNC
 */
HWTEST_F(GECacheHelperTest, IsSDFCacheEnabled_ZeroFlagWithTrueDefault, TestSize.Level1)
{
    int originalFlag = GECacheHelper::SDFCacheSystemFlag_;
    GECacheHelper::SDFCacheSystemFlag_ = 0;
    EXPECT_FALSE(GECacheHelper::IsSDFCacheEnabled(true));
    GECacheHelper::SDFCacheSystemFlag_ = originalFlag;
}

/**
 * @tc.name: IsSDFCacheEnabled_ZeroFlagWithFalseDefault
 * @tc.desc: Verify IsSDFCacheEnabled forces false when SDFCacheSystemFlag_ == 0 and defaultValue is false
 * @tc.type: FUNC
 */
HWTEST_F(GECacheHelperTest, IsSDFCacheEnabled_ZeroFlagWithFalseDefault, TestSize.Level1)
{
    int originalFlag = GECacheHelper::SDFCacheSystemFlag_;
    GECacheHelper::SDFCacheSystemFlag_ = 0;
    EXPECT_FALSE(GECacheHelper::IsSDFCacheEnabled(false));
    GECacheHelper::SDFCacheSystemFlag_ = originalFlag;
}

/**
 * @tc.name: IsSDFCacheEnabled_PositiveFlagWithTrueDefault
 * @tc.desc: Verify IsSDFCacheEnabled forces true when SDFCacheSystemFlag_ > 0 and defaultValue is true
 * @tc.type: FUNC
 */
HWTEST_F(GECacheHelperTest, IsSDFCacheEnabled_PositiveFlagWithTrueDefault, TestSize.Level1)
{
    int originalFlag = GECacheHelper::SDFCacheSystemFlag_;
    GECacheHelper::SDFCacheSystemFlag_ = 1;
    EXPECT_TRUE(GECacheHelper::IsSDFCacheEnabled(true));
    GECacheHelper::SDFCacheSystemFlag_ = originalFlag;
}

/**
 * @tc.name: IsSDFCacheEnabled_PositiveFlagWithFalseDefault
 * @tc.desc: Verify IsSDFCacheEnabled forces true when SDFCacheSystemFlag_ > 0 and defaultValue is false
 * @tc.type: FUNC
 */
HWTEST_F(GECacheHelperTest, IsSDFCacheEnabled_PositiveFlagWithFalseDefault, TestSize.Level1)
{
    int originalFlag = GECacheHelper::SDFCacheSystemFlag_;
    GECacheHelper::SDFCacheSystemFlag_ = 1;
    EXPECT_TRUE(GECacheHelper::IsSDFCacheEnabled(false));
    GECacheHelper::SDFCacheSystemFlag_ = originalFlag;
}
} // namespace Rosen
} // namespace OHOS
