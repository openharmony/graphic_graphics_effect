# graphics_effect

## 介绍
Graphics Effect是OpenHarmony图形子系统的重要部件，为图形子系统提供必需的动视效算法能力，包括模糊、阴影、渐变、灰阶、提亮、反色、取色等。

## 软件架构
![GraphicsEffect架构图](./figures/graphics_effect_architecture.png)

Graphics Effect的分层说明如下：

• 接口层：Graphics Effect通过ArkUI、UIEffect、EffectKit对外开放能力。

• 实现层：分为GERender、GEVisualEffect、GEVisualEffectContainer三个模块。
| 模块                            | 能力描述                            |
|-------------------------------|---------------------------------------|
| GERender（渲染）                  | 提供绘制能力，将GEVisualEffect效果绘制到canvas画布上。 |
| GEVisualEffect（动视效）            | 具体动视效能力的实现。                          |
| GEVisualEffectContainer（动视效容器） | 多个动视效方便集成。                           |

## 目录结构
```
foundation/graphic/graphics_effect/
├── figures                 # Markdown引用的图片目录
├── include                 # Graphics Effect接口存放目录
│   ├── ext                 # 动态加载框架及算法接口存放目录
├── src                     # 源代码存放目录
│   ├── ext                 # 动态加载框架及算法接口实现存放目录
└── test                    # 测试用例存放目录
    ├── fuzztest            # fuzz用例存放目录
    └── unittest            # 单元测试用例存放目录
```

## 安装教程

不涉及

## 使用说明

在桌面、状态栏、控制中心等系统UI场景中已经集成了该部件的能力，用户可直接操作使用并体验相应效果。

### 1.将指定动视效绘制到画布上

以Image为基础，应用GEVisualEffectContainer所包含的动视效，并直接绘制到传入的canvas画布上
```
void DrawImageEffect(Drawing::Canvas& canvas, Drawing::GEVisualEffectContainer& veContainer,
        const std::shared_ptr<Drawing::Image>& image, const Drawing::Rect& src, const Drawing::Rect& dst,
        const Drawing::SamplingOptions& sampling);
```
调用示例：
```
  Drawing::Canvas canvas;
  auto image = std::make_shared<Drawing::Image>();
  auto visualEffectContainer = std::make_shared<Drawing::GEVisualEffectContainer>();
  DrawImageRectAttributes attr;

  auto geRender = std::make_shared<GraphicsEffectEngine::GERender>();
  geRender->DrawImageEffect(canvas, *visualEffectContainer, image, attr.src, attr.src, Drawing::SamplingOptions());
```

### 2.将指定动视效绘制到画布上并以图片形式返回绘制结果

以Image为基础，应用GEVisualEffectContainer所包含的动视效，并返回新的Image
```
std::shared_ptr<Drawing::Image> ApplyImageEffect(Drawing::Canvas& canvas,
        Drawing::GEVisualEffectContainer& veContainer, const std::shared_ptr<Drawing::Image>& image,
        const Drawing::Rect& src, const Drawing::Rect& dst, const Drawing::SamplingOptions& sampling);
```
调用示例：
```
  Drawing::Canvas canvas;
  auto image = std::make_shared<Drawing::Image>();
  auto visualEffectContainer = std::make_shared<Drawing::GEVisualEffectContainer>();
  DrawImageRectAttributes attr;

  auto geRender = std::make_shared<GraphicsEffectEngine::GERender>();
  auto outImage = geRender->ApplyImageEffect(canvas, *visualEffectContainer, image, attr.src, attr.src, Drawing::SamplingOptions());
```

