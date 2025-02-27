# graphics_effect

#### Description
graphics_effect is an important component of OpenHarmony's graphics subsystem, providing the necessary visual effects algorithm capabilities for the graphics subsystem, including blur, shadow, gradient, grayscale, brighten, invert, enhance, etc.

#### Software Architecture
![GraphicsEffectArchitecture](./figures/graphics_effect_architecture.png)

The layered description of Graphics Effect is as follows:

• Interface layer: Graphics Effect opens its capabilities to the outside world through ArkUI, UIEffect, and EffectKit.

• Implementation layer: divided into three modules: GERender, GEVisualEffect, and GEVisualEffectContainer.
| Modules                                          | Capability description                                                                 |
|--------------------------------------------------|----------------------------------------------------------------------------------------|
| GERender(rendering)                              | provides drawing capabilities and draws the effects of GEVisualEffect onto the target. |
| GEVisualEffect(visual effect)                    | implementation of specific visual effect capabilities.                                 |
| GEVisualEffectContainer(visual effect container) | convenient integration of multiple visual effects.                                     |

• Engine encapsulation layer: encapsulation layerof 2D engine provided by the system.

#### Installation

Not involved

#### Instructions

The capabilities of this component have been integrated into system UI rendering scenarios such as the desktop, status bar, and control center, and users can directly operate and use it and experience the corresponding effects.

#### Contribution

1.  Fork the repository
2.  Create Feat_xxx branch
3.  Commit your code
4.  Create Pull Request


#### Gitee Feature

1.  You can use Readme\_XXX.md to support different languages, such as Readme\_en.md, Readme\_zh.md
2.  Gitee blog [blog.gitee.com](https://blog.gitee.com)
3.  Explore open source project [https://gitee.com/explore](https://gitee.com/explore)
4.  The most valuable open source project [GVP](https://gitee.com/gvp)
5.  The manual of Gitee [https://gitee.com/help](https://gitee.com/help)
6.  The most popular members  [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
