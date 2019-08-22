## Linux驱动模型platform

1. Linux加入了一套驱动管理和注册机制
   + platform平台总线驱动模型。
2. 内核中的设备: 需要设备号, 通过注册得到;

### platform平台总线

1. platform平台总线是一条虚拟总线

   + platform_device为相应的设备
   + platform_driver为相应的驱动

2. 与传统的bus/device/driver机制相比，platform由内核统一进行管理;提高了代码的可移植性和安全性

3. Linux总线设备驱动模型的框架

   ![platform.png](https://github.com/quronghui/Embedded-written-reference/blob/master/OS/photo/platform.png)

   + 总线、设备和驱动这3个实体，同时总线将设备和驱动**绑定**
     + match() : 进行匹配
     + probe(): 进行绑定 
   + platform_driver_register
     + 将驱动程序注册到总线，并将其放入所属总线的drv链表中
     + 调用所属总线的match函数 : 寻找该总线上与之匹配的每一个设备，
     + probe函数 : 将相应的设备和驱动进行绑定
   + platform_device_register
     + 将设备注册到总线，并将其放入所属总线的dev链表中
     + 调用所属总线的**match函数**: 寻找该总线上与之匹配的每一个驱动程序，
     + **probe函数**: 将相应的设备和驱动进行绑定