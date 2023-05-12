# UnrealEngine5_NvidiaAnsel
一个基于Unreal Engine4.27 版本Nvidia Ansel移植而来的版本，提供两个版本，普通版本和自动抓取版本.

修正：安装存在的部分的瑕疵，规范了build.cs文件
## update
更新5.2版本，添加更多设置选项：
![image](https://github.com/MonsterGuo/UE5_NvidiaAnsel/assets/39860733/303d32df-57e9-492a-a3e2-a93c438cc1b6)

# 安装：将插件安装到任意，引擎能识别到插件的位置即可

# Ansel_Capture
一个基于 Unreal Engine 4.27 修改的Nvidia_Ansel plugins 可以用于生成360 或者立体360 影片的工具 
这是基于Unreal Engine 4.27 的Ansel插件修改而来的版本。
在开始你的工作之前你需要做好一下准备：
#### 1.确认您的显卡已经安装好显卡驱动：
目前已经测试了：456.71~551.79版本的Nvidia驱动。
#### 2.假如你需要更改单帧的保存位置：请安装Nvidia的GeForceExperience组件。
**没有修改：将默认保存在系统指定的”视频文件夹下方“

（1）点击“设置”

![Pasted image 20220324120858](https://user-images.githubusercontent.com/39860733/159846088-18804c78-c19a-47ca-8edc-ea44e3d7a3af.png)
（2）关闭“游戏内覆盖”，这一步是为了确保“Ansel”能正常启动，这里为啥我也不大清楚。反正必须关掉，虚幻内部的Ansel才能启动。

![Pasted image 20220324121037](https://user-images.githubusercontent.com/39860733/159846137-8b6e1ee7-57e3-4cb8-b1bb-c78f52e559b2.png)
（3）点击“游戏内覆”盖设置

![Pasted image 20220324120645](https://user-images.githubusercontent.com/39860733/159846194-877e800a-cc0b-48e6-9712-8b22d08c5ee8.png)
（4）点击“设置”选项

![Pasted image 20220324121245](https://user-images.githubusercontent.com/39860733/159846343-153054d9-3cf0-4304-b42d-8202dafcbe8e.png)
（5）设置保存路径

![Pasted image 20220324122738](https://user-images.githubusercontent.com/39860733/159846366-b01d8273-55bc-4cd4-9ff7-26e082e122e4.png)
![Pasted image 20220324122852](https://user-images.githubusercontent.com/39860733/159846373-489b35b0-f155-4791-80d8-2cbacb7be82b.png)
#### 3.下方就是在虚幻4中普通使用的一个情景
1.先关闭场景的”自动曝光“，这里的值可以根据自己的预设值设定。

![Pasted image 20220324125255](https://user-images.githubusercontent.com/39860733/159846410-f6ff752d-283a-41c4-9fdd-45e8394a5bd6.png)  

