//
//  common_ob.h
//  TSServerPro
//
//  Created by li haijin on 13-1-28.
//  Copyright (c) 2013年 li haijin. All rights reserved.
//

#ifndef TSServerPro_common_ob_h
#define TSServerPro_common_ob_h

typedef enum {
    TSNO = 0,
    TSYES = 1
}TSBOOL;

//about packet type.
typedef enum {
    PACKET_HEART_BEAT = '0',
    PACKET_USER_INFO,
    PACKET_OTHER_DATA
}PACKET_TYPE;

//about driver gender type
typedef enum {
    MAN = 0,
    WOMAN,
    OTHER     //MGD
    
}GENDER_TYPE;

//about driver integrity type
typedef enum {
    INTEGRITY_QUALITY_POOR = 0,
    INTEGRITY_QUALITY_GENERAL,
    INTEGRITY_QUALITY_GOOD,
    INTEGRITY_QUALITY_EXCELLENT
}INTEGRITY_QUALITY_TYPE;

//路段质量
typedef enum {
    ROUTE_QUALITY_POOR = 0,
    ROUTE_QUALITY_GENERAL,
    ROUTE_QUALITY_GOOD,
    ROUTE_QUALITY_EXCELLENT
}ROUTE_QUALITY_TYPE;

//路段拥挤程度
typedef enum {
    TRAFFIC_STREAM_EXPEDITE = 0,  //畅通
    TRAFFIC_STREAM_AMBLE,         //缓行
    TRAFFIC_STREAM_CROWDED        //拥挤
}TRAFFIC_STREAM_TYPE;

//交通工具类型
typedef enum {
    TRANSPORTATION_BUS = 0,
    TRANSPORTATION_TAXI
}TRANSPORTATION_TYPE;

//about packet ob
typedef struct {
    PACKET_TYPE type;
    size_t length;
    char *data;
}PacketStruct;

//about geographic coordinate
typedef struct {
    float longitude;
    float latitude;
}GeographicCoordinate;

//about city info
typedef struct {
    GeographicCoordinate geoCoordSys;
    char *cityName;
}CityInfo;

//about driver info
typedef struct {
    char *_driverID; //身份证
    char *_name;
    int _age;
    char *_headImage;
    GENDER_TYPE _gender;
    int _driverYears;
    TSBOOL _isHaveInfractionsHistory; //违规历史记录
    INTEGRITY_QUALITY_TYPE *_driverIntegrity;  //驾驶员诚信度
}DriverInfo;

//about route info
typedef struct {
    ROUTE_QUALITY_TYPE *_routeType;
    long int _pathLenth;
    GeographicCoordinate *_startPlace;
    GeographicCoordinate *_endPlace;
}RouteInfo;


//about transportation
typedef struct {
    char *_transportationID;   //车牌号
    char *_carTypeInfo;
    char *_carImage;
    TRANSPORTATION_TYPE *_transportationType;
    float _averageSpeed;
    
    DriverInfo *_driver;
}Transportation;

//about passenger info
typedef struct {
    char *_passengerName;
    GeographicCoordinate *_passengerPlace;
    INTEGRITY_QUALITY_TYPE *_passengerIntegrity;
}PassengerInfo;









#endif
