-- Generated By protoc-gen-lua Do not Edit
local protobuf = require "protobuf/protobuf"
local client2world_msg_type_pb = require("client2world_msg_type_pb")
local msg_type_def_pb = require("msg_type_def_pb")
local msg_info_def_pb = require("msg_info_def_pb")
module('client2world_exchange_pb')


PACKETC2W_EXCHANGE = protobuf.Descriptor();
local PACKETC2W_EXCHANGE_PACKET_ID_FIELD = protobuf.FieldDescriptor();
local PACKETC2W_EXCHANGE_EXCHANGEID_FIELD = protobuf.FieldDescriptor();
local PACKETC2W_EXCHANGE_PHONE_FIELD = protobuf.FieldDescriptor();
PACKETW2C_EXCHANGE_RESULT = protobuf.Descriptor();
local PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD = protobuf.FieldDescriptor();
local PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD = protobuf.FieldDescriptor();
local PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD = protobuf.FieldDescriptor();
PACKETC2W_GET_EXCHANGE_STATE = protobuf.Descriptor();
local PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD = protobuf.FieldDescriptor();
EXCHANGEINFO = protobuf.Descriptor();
local EXCHANGEINFO_TIME_FIELD = protobuf.FieldDescriptor();
local EXCHANGEINFO_CHGID_FIELD = protobuf.FieldDescriptor();
local EXCHANGEINFO_ISRECEIVE_FIELD = protobuf.FieldDescriptor();
PACKETW2C_GET_EXCHANGE_STATE_RESULT = protobuf.Descriptor();
local PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD = protobuf.FieldDescriptor();
local PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD = protobuf.FieldDescriptor();
PACKETC2W_SHOPPING = protobuf.Descriptor();
local PACKETC2W_SHOPPING_PACKET_ID_FIELD = protobuf.FieldDescriptor();
local PACKETC2W_SHOPPING_SHOPID_FIELD = protobuf.FieldDescriptor();
PACKETW2C_SHOPPING_RESULT = protobuf.Descriptor();
local PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD = protobuf.FieldDescriptor();
local PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD = protobuf.FieldDescriptor();
local PACKETW2C_SHOPPING_RESULT_RESULT_FIELD = protobuf.FieldDescriptor();

PACKETC2W_EXCHANGE_PACKET_ID_FIELD.name = "packet_id"
PACKETC2W_EXCHANGE_PACKET_ID_FIELD.full_name = ".client2world_protocols.packetc2w_exchange.packet_id"
PACKETC2W_EXCHANGE_PACKET_ID_FIELD.number = 1
PACKETC2W_EXCHANGE_PACKET_ID_FIELD.index = 0
PACKETC2W_EXCHANGE_PACKET_ID_FIELD.label = 1
PACKETC2W_EXCHANGE_PACKET_ID_FIELD.enum_type = client2world_msg_type_pb.E_SERVER_MSG_TYPE
PACKETC2W_EXCHANGE_PACKET_ID_FIELD.has_default_value = true
PACKETC2W_EXCHANGE_PACKET_ID_FIELD.default_value = client2world_msg_type_pb.e_mst_c2w_exchange
PACKETC2W_EXCHANGE_PACKET_ID_FIELD.type = 14
PACKETC2W_EXCHANGE_PACKET_ID_FIELD.cpp_type = 8

PACKETC2W_EXCHANGE_EXCHANGEID_FIELD.name = "exchangeId"
PACKETC2W_EXCHANGE_EXCHANGEID_FIELD.full_name = ".client2world_protocols.packetc2w_exchange.exchangeId"
PACKETC2W_EXCHANGE_EXCHANGEID_FIELD.number = 2
PACKETC2W_EXCHANGE_EXCHANGEID_FIELD.index = 1
PACKETC2W_EXCHANGE_EXCHANGEID_FIELD.label = 1
PACKETC2W_EXCHANGE_EXCHANGEID_FIELD.has_default_value = false
PACKETC2W_EXCHANGE_EXCHANGEID_FIELD.default_value = 0
PACKETC2W_EXCHANGE_EXCHANGEID_FIELD.type = 5
PACKETC2W_EXCHANGE_EXCHANGEID_FIELD.cpp_type = 1

PACKETC2W_EXCHANGE_PHONE_FIELD.name = "phone"
PACKETC2W_EXCHANGE_PHONE_FIELD.full_name = ".client2world_protocols.packetc2w_exchange.phone"
PACKETC2W_EXCHANGE_PHONE_FIELD.number = 3
PACKETC2W_EXCHANGE_PHONE_FIELD.index = 2
PACKETC2W_EXCHANGE_PHONE_FIELD.label = 1
PACKETC2W_EXCHANGE_PHONE_FIELD.has_default_value = false
PACKETC2W_EXCHANGE_PHONE_FIELD.default_value = ""
PACKETC2W_EXCHANGE_PHONE_FIELD.type = 9
PACKETC2W_EXCHANGE_PHONE_FIELD.cpp_type = 9

PACKETC2W_EXCHANGE.name = "packetc2w_exchange"
PACKETC2W_EXCHANGE.full_name = ".client2world_protocols.packetc2w_exchange"
PACKETC2W_EXCHANGE.nested_types = {}
PACKETC2W_EXCHANGE.enum_types = {}
PACKETC2W_EXCHANGE.fields = {PACKETC2W_EXCHANGE_PACKET_ID_FIELD, PACKETC2W_EXCHANGE_EXCHANGEID_FIELD, PACKETC2W_EXCHANGE_PHONE_FIELD}
PACKETC2W_EXCHANGE.is_extendable = false
PACKETC2W_EXCHANGE.extensions = {}
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.name = "packet_id"
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.full_name = ".client2world_protocols.packetw2c_exchange_result.packet_id"
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.number = 1
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.index = 0
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.label = 1
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.enum_type = client2world_msg_type_pb.E_SERVER_MSG_TYPE
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.has_default_value = true
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.default_value = client2world_msg_type_pb.e_mst_w2c_exchange_result
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.type = 14
PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD.cpp_type = 8

PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD.name = "exchangeId"
PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD.full_name = ".client2world_protocols.packetw2c_exchange_result.exchangeId"
PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD.number = 2
PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD.index = 1
PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD.label = 1
PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD.has_default_value = false
PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD.default_value = 0
PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD.type = 5
PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD.cpp_type = 1

PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD.name = "result"
PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD.full_name = ".client2world_protocols.packetw2c_exchange_result.result"
PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD.number = 3
PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD.index = 2
PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD.label = 1
PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD.has_default_value = false
PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD.default_value = 0
PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD.type = 5
PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD.cpp_type = 1

PACKETW2C_EXCHANGE_RESULT.name = "packetw2c_exchange_result"
PACKETW2C_EXCHANGE_RESULT.full_name = ".client2world_protocols.packetw2c_exchange_result"
PACKETW2C_EXCHANGE_RESULT.nested_types = {}
PACKETW2C_EXCHANGE_RESULT.enum_types = {}
PACKETW2C_EXCHANGE_RESULT.fields = {PACKETW2C_EXCHANGE_RESULT_PACKET_ID_FIELD, PACKETW2C_EXCHANGE_RESULT_EXCHANGEID_FIELD, PACKETW2C_EXCHANGE_RESULT_RESULT_FIELD}
PACKETW2C_EXCHANGE_RESULT.is_extendable = false
PACKETW2C_EXCHANGE_RESULT.extensions = {}
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.name = "packet_id"
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.full_name = ".client2world_protocols.packetc2w_get_exchange_state.packet_id"
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.number = 1
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.index = 0
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.label = 1
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.enum_type = client2world_msg_type_pb.E_SERVER_MSG_TYPE
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.has_default_value = true
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.default_value = client2world_msg_type_pb.e_mst_c2w_get_exchange_state
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.type = 14
PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD.cpp_type = 8

PACKETC2W_GET_EXCHANGE_STATE.name = "packetc2w_get_exchange_state"
PACKETC2W_GET_EXCHANGE_STATE.full_name = ".client2world_protocols.packetc2w_get_exchange_state"
PACKETC2W_GET_EXCHANGE_STATE.nested_types = {}
PACKETC2W_GET_EXCHANGE_STATE.enum_types = {}
PACKETC2W_GET_EXCHANGE_STATE.fields = {PACKETC2W_GET_EXCHANGE_STATE_PACKET_ID_FIELD}
PACKETC2W_GET_EXCHANGE_STATE.is_extendable = false
PACKETC2W_GET_EXCHANGE_STATE.extensions = {}
EXCHANGEINFO_TIME_FIELD.name = "time"
EXCHANGEINFO_TIME_FIELD.full_name = ".client2world_protocols.ExchangeInfo.time"
EXCHANGEINFO_TIME_FIELD.number = 1
EXCHANGEINFO_TIME_FIELD.index = 0
EXCHANGEINFO_TIME_FIELD.label = 1
EXCHANGEINFO_TIME_FIELD.has_default_value = false
EXCHANGEINFO_TIME_FIELD.default_value = 0
EXCHANGEINFO_TIME_FIELD.type = 5
EXCHANGEINFO_TIME_FIELD.cpp_type = 1

EXCHANGEINFO_CHGID_FIELD.name = "chgId"
EXCHANGEINFO_CHGID_FIELD.full_name = ".client2world_protocols.ExchangeInfo.chgId"
EXCHANGEINFO_CHGID_FIELD.number = 2
EXCHANGEINFO_CHGID_FIELD.index = 1
EXCHANGEINFO_CHGID_FIELD.label = 1
EXCHANGEINFO_CHGID_FIELD.has_default_value = false
EXCHANGEINFO_CHGID_FIELD.default_value = 0
EXCHANGEINFO_CHGID_FIELD.type = 5
EXCHANGEINFO_CHGID_FIELD.cpp_type = 1

EXCHANGEINFO_ISRECEIVE_FIELD.name = "isReceive"
EXCHANGEINFO_ISRECEIVE_FIELD.full_name = ".client2world_protocols.ExchangeInfo.isReceive"
EXCHANGEINFO_ISRECEIVE_FIELD.number = 3
EXCHANGEINFO_ISRECEIVE_FIELD.index = 2
EXCHANGEINFO_ISRECEIVE_FIELD.label = 1
EXCHANGEINFO_ISRECEIVE_FIELD.has_default_value = false
EXCHANGEINFO_ISRECEIVE_FIELD.default_value = false
EXCHANGEINFO_ISRECEIVE_FIELD.type = 8
EXCHANGEINFO_ISRECEIVE_FIELD.cpp_type = 7

EXCHANGEINFO.name = "ExchangeInfo"
EXCHANGEINFO.full_name = ".client2world_protocols.ExchangeInfo"
EXCHANGEINFO.nested_types = {}
EXCHANGEINFO.enum_types = {}
EXCHANGEINFO.fields = {EXCHANGEINFO_TIME_FIELD, EXCHANGEINFO_CHGID_FIELD, EXCHANGEINFO_ISRECEIVE_FIELD}
EXCHANGEINFO.is_extendable = false
EXCHANGEINFO.extensions = {}
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.name = "packet_id"
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.full_name = ".client2world_protocols.packetw2c_get_exchange_state_result.packet_id"
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.number = 1
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.index = 0
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.label = 1
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.enum_type = client2world_msg_type_pb.E_SERVER_MSG_TYPE
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.has_default_value = true
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.default_value = client2world_msg_type_pb.e_mst_w2c_get_exchange_state_result
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.type = 14
PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD.cpp_type = 8

PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.name = "infoList"
PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.full_name = ".client2world_protocols.packetw2c_get_exchange_state_result.infoList"
PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.number = 2
PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.index = 1
PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.label = 3
PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.message_type = EXCHANGEINFO
PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.has_default_value = false
PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.default_value = {}
PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.type = 11
PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD.cpp_type = 10

PACKETW2C_GET_EXCHANGE_STATE_RESULT.name = "packetw2c_get_exchange_state_result"
PACKETW2C_GET_EXCHANGE_STATE_RESULT.full_name = ".client2world_protocols.packetw2c_get_exchange_state_result"
PACKETW2C_GET_EXCHANGE_STATE_RESULT.nested_types = {}
PACKETW2C_GET_EXCHANGE_STATE_RESULT.enum_types = {}
PACKETW2C_GET_EXCHANGE_STATE_RESULT.fields = {PACKETW2C_GET_EXCHANGE_STATE_RESULT_PACKET_ID_FIELD, PACKETW2C_GET_EXCHANGE_STATE_RESULT_INFOLIST_FIELD}
PACKETW2C_GET_EXCHANGE_STATE_RESULT.is_extendable = false
PACKETW2C_GET_EXCHANGE_STATE_RESULT.extensions = {}
PACKETC2W_SHOPPING_PACKET_ID_FIELD.name = "packet_id"
PACKETC2W_SHOPPING_PACKET_ID_FIELD.full_name = ".client2world_protocols.packetc2w_shopping.packet_id"
PACKETC2W_SHOPPING_PACKET_ID_FIELD.number = 1
PACKETC2W_SHOPPING_PACKET_ID_FIELD.index = 0
PACKETC2W_SHOPPING_PACKET_ID_FIELD.label = 1
PACKETC2W_SHOPPING_PACKET_ID_FIELD.enum_type = client2world_msg_type_pb.E_SERVER_MSG_TYPE
PACKETC2W_SHOPPING_PACKET_ID_FIELD.has_default_value = true
PACKETC2W_SHOPPING_PACKET_ID_FIELD.default_value = client2world_msg_type_pb.e_mst_c2w_shopping
PACKETC2W_SHOPPING_PACKET_ID_FIELD.type = 14
PACKETC2W_SHOPPING_PACKET_ID_FIELD.cpp_type = 8

PACKETC2W_SHOPPING_SHOPID_FIELD.name = "shopid"
PACKETC2W_SHOPPING_SHOPID_FIELD.full_name = ".client2world_protocols.packetc2w_shopping.shopid"
PACKETC2W_SHOPPING_SHOPID_FIELD.number = 2
PACKETC2W_SHOPPING_SHOPID_FIELD.index = 1
PACKETC2W_SHOPPING_SHOPID_FIELD.label = 1
PACKETC2W_SHOPPING_SHOPID_FIELD.has_default_value = false
PACKETC2W_SHOPPING_SHOPID_FIELD.default_value = 0
PACKETC2W_SHOPPING_SHOPID_FIELD.type = 5
PACKETC2W_SHOPPING_SHOPID_FIELD.cpp_type = 1

PACKETC2W_SHOPPING.name = "packetc2w_shopping"
PACKETC2W_SHOPPING.full_name = ".client2world_protocols.packetc2w_shopping"
PACKETC2W_SHOPPING.nested_types = {}
PACKETC2W_SHOPPING.enum_types = {}
PACKETC2W_SHOPPING.fields = {PACKETC2W_SHOPPING_PACKET_ID_FIELD, PACKETC2W_SHOPPING_SHOPID_FIELD}
PACKETC2W_SHOPPING.is_extendable = false
PACKETC2W_SHOPPING.extensions = {}
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.name = "packet_id"
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.full_name = ".client2world_protocols.packetw2c_shopping_result.packet_id"
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.number = 1
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.index = 0
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.label = 1
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.enum_type = client2world_msg_type_pb.E_SERVER_MSG_TYPE
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.has_default_value = true
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.default_value = client2world_msg_type_pb.e_mst_w2c_shopping_result
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.type = 14
PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD.cpp_type = 8

PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD.name = "shopid"
PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD.full_name = ".client2world_protocols.packetw2c_shopping_result.shopid"
PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD.number = 2
PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD.index = 1
PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD.label = 1
PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD.has_default_value = false
PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD.default_value = 0
PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD.type = 5
PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD.cpp_type = 1

PACKETW2C_SHOPPING_RESULT_RESULT_FIELD.name = "result"
PACKETW2C_SHOPPING_RESULT_RESULT_FIELD.full_name = ".client2world_protocols.packetw2c_shopping_result.result"
PACKETW2C_SHOPPING_RESULT_RESULT_FIELD.number = 3
PACKETW2C_SHOPPING_RESULT_RESULT_FIELD.index = 2
PACKETW2C_SHOPPING_RESULT_RESULT_FIELD.label = 1
PACKETW2C_SHOPPING_RESULT_RESULT_FIELD.has_default_value = false
PACKETW2C_SHOPPING_RESULT_RESULT_FIELD.default_value = 0
PACKETW2C_SHOPPING_RESULT_RESULT_FIELD.type = 5
PACKETW2C_SHOPPING_RESULT_RESULT_FIELD.cpp_type = 1

PACKETW2C_SHOPPING_RESULT.name = "packetw2c_shopping_result"
PACKETW2C_SHOPPING_RESULT.full_name = ".client2world_protocols.packetw2c_shopping_result"
PACKETW2C_SHOPPING_RESULT.nested_types = {}
PACKETW2C_SHOPPING_RESULT.enum_types = {}
PACKETW2C_SHOPPING_RESULT.fields = {PACKETW2C_SHOPPING_RESULT_PACKET_ID_FIELD, PACKETW2C_SHOPPING_RESULT_SHOPID_FIELD, PACKETW2C_SHOPPING_RESULT_RESULT_FIELD}
PACKETW2C_SHOPPING_RESULT.is_extendable = false
PACKETW2C_SHOPPING_RESULT.extensions = {}

ExchangeInfo = protobuf.Message(EXCHANGEINFO)
packetc2w_exchange = protobuf.Message(PACKETC2W_EXCHANGE)
packetc2w_get_exchange_state = protobuf.Message(PACKETC2W_GET_EXCHANGE_STATE)
packetc2w_shopping = protobuf.Message(PACKETC2W_SHOPPING)
packetw2c_exchange_result = protobuf.Message(PACKETW2C_EXCHANGE_RESULT)
packetw2c_get_exchange_state_result = protobuf.Message(PACKETW2C_GET_EXCHANGE_STATE_RESULT)
packetw2c_shopping_result = protobuf.Message(PACKETW2C_SHOPPING_RESULT)

