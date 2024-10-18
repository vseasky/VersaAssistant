# 通信协议

## 接口协议说明

- 以下所有低位在前发送

1. 通信协议格式

| **帧头**          | **数据段**                                | **帧尾**                               |
| ----------------- | ----------------------------------------- | -------------------------------------- |
| *header*(*5byte*) | *frame_user*((*9*+(*uLen* \* *4*))*byte*) | *frame_tail*(*2byte*，crc16，整包校验) |

2. 帧头 *header* 定义

字节偏移 [*0*]，字节大小 [*5byte*]

| *帧头*        | 偏移位置 | 字节大小 | 内容                                                         |
| ------------- | -------- | -------- | ------------------------------------------------------------ |
| *fixed*       | 0        | 2        | 数据帧起始字节，固定值为 `0x5A53`                            |
| *data_length* | 2        | 2        | 数据帧 *frame_user* 中 *data* 的长度 *uLen \*4*，单位 *byte* |
| *crc_check*   | 4        | 1        | 帧头crc校验                                                  |

3. 数据段 *frame_user* 定义

字节偏移 [*5*]，字节大小 [(*9*+(*uLen* \* *4*))*byte*]

| *数据*        | 偏移位置 | 字节大小  | 功能说明                                                                     |
| ------------- | -------- | --------- | ---------------------------------------------------------------------------- |
| *cmd*         | 5        | 1         | 功能码。                                                                     |
| *device_type* | 6        | 2         | 模块类型，可以区分传感器、控制器、或产品类型，对于同一个分类，该值一般固定。 |
| *device_id*   | 8        | 4         | 模块ID，可以区分同一个传感器、控制器、或产品的不同个体，一般需要可以设置。   |
| *data_id*     | 12       | 2         | 数据ID，可以指定模块的某类数据，具体由模块本身决定。                         |
| *data*        | 14       | *uLen\*4* | 数据                                                                         |

4. 帧尾 *frame_tail* (crc16，整包校验)

字节偏移 [*5* + *9* + (*uLen* * *4byte*)]，字节大小 [*2*]

| *帧尾*       | 偏移位置                     | 字节大小 | 功能说明 |
| ------------ | ---------------------------- | -------- | -------- |
| *frame_tail* | *5* + *9*+(*uLen* * *4byte*) | 2        | 帧尾校验 |

5. 通信协议依赖文件(CRC8,CRC16算法)

> bsp_crc16.h
> bsp_crc16.c
> bsp_crc8.h
> bsp_crc8.c
