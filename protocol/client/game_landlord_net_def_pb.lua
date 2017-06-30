-- Generated By protoc-gen-lua Do not Edit
local protobuf = require "protobuf/protobuf"
module('game_landlord_net_def_pb')


E_SERVER_MSG_TYPE = protobuf.EnumDescriptor();
E_SERVER_MSG_TYPE_E_MST_START_C2L_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_ENTER_ROOM_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_GET_ROOM_SCENE_INFO_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_CHECK_STATE_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_LEAVE_ROOM_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_ROB_LANDLORD_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_PLAYHAND_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_START_MATCH_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_HANG_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_SYSTEMTALK_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_ROOMLIST_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_HANG_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_ROOMLIST_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WHO_PLAYHAND_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_SYSTEMTALK_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_ENTER_LEAVE_INFO_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_PREPARE_INFO_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_CHANGE_INFO_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_CLEND_INDEX_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_ERROR_CODE = protobuf.EnumDescriptor();
E_SERVER_ERROR_CODE_E_ERROR_CODE_SUCCESS_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_ERROR_CODE_E_ERROR_CODE_FAILED_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_ERROR_CODE_E_ERROR_CODE_NOT_ENOUGH_MONEY_ENUM = protobuf.EnumValueDescriptor();
E_GAME_STATE = protobuf.EnumDescriptor();
E_GAME_STATE_E_GAME_STATE_NONE_ENUM = protobuf.EnumValueDescriptor();
E_GAME_STATE_E_GAME_STATE_MATCHING_ENUM = protobuf.EnumValueDescriptor();
E_GAME_STATE_E_GAME_STATE_STARTGAME_ENUM = protobuf.EnumValueDescriptor();
E_GAME_STATE_E_GAME_STATE_SENDCARDING_ENUM = protobuf.EnumValueDescriptor();
E_GAME_STATE_E_GAME_STATE_ROBLANDLORE_ENUM = protobuf.EnumValueDescriptor();
E_GAME_STATE_E_GAME_STATE_PLAYHAND_ENUM = protobuf.EnumValueDescriptor();
E_GAME_STATE_E_GAME_STATE_AWARD_ENUM = protobuf.EnumValueDescriptor();
E_PLAYER_GAME_STATE = protobuf.EnumDescriptor();
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_NONE_ENUM = protobuf.EnumValueDescriptor();
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_MATCHING_ENUM = protobuf.EnumValueDescriptor();
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_SENDCARDING_ENUM = protobuf.EnumValueDescriptor();
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_ROBLANDLORD_ENUM = protobuf.EnumValueDescriptor();
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_ROBLANDLORD_ENUM = protobuf.EnumValueDescriptor();
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_PLAYHANDING_ENUM = protobuf.EnumValueDescriptor();
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_PLAYHANDING_ENUM = protobuf.EnumValueDescriptor();
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_AWARDING_ENUM = protobuf.EnumValueDescriptor();
CARD_INFO = protobuf.Descriptor();
local CARD_INFO_DESKID_FIELD = protobuf.FieldDescriptor();
local CARD_INFO_CARDS_FIELD = protobuf.FieldDescriptor();
CARD_INFO_1 = protobuf.Descriptor();
local CARD_INFO_1_DESKID_FIELD = protobuf.FieldDescriptor();
local CARD_INFO_1_CARDS_COUNT_FIELD = protobuf.FieldDescriptor();
DESK_AWARD_INFO = protobuf.Descriptor();
local DESK_AWARD_INFO_DESKID_FIELD = protobuf.FieldDescriptor();
local DESK_AWARD_INFO_WIN_COUNT_FIELD = protobuf.FieldDescriptor();
PLAYER_INFO = protobuf.Descriptor();
local PLAYER_INFO_PLAYER_ID_FIELD = protobuf.FieldDescriptor();
local PLAYER_INFO_PLAYER_NICKNAME_FIELD = protobuf.FieldDescriptor();
local PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD = protobuf.FieldDescriptor();
local PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD = protobuf.FieldDescriptor();
local PLAYER_INFO_PLAYER_GOLD_FIELD = protobuf.FieldDescriptor();
local PLAYER_INFO_PLAYER_SEX_FIELD = protobuf.FieldDescriptor();
local PLAYER_INFO_PLAYER_VIP_LV_FIELD = protobuf.FieldDescriptor();
local PLAYER_INFO_DESKID_FIELD = protobuf.FieldDescriptor();
local PLAYER_INFO_ORPREPARE_FIELD = protobuf.FieldDescriptor();
ROOM_INFO = protobuf.Descriptor();
local ROOM_INFO_ROOM_ID_FIELD = protobuf.FieldDescriptor();
local ROOM_INFO_PLAYER_COUNT_FIELD = protobuf.FieldDescriptor();
local ROOM_INFO_ROOM_STATE_FIELD = protobuf.FieldDescriptor();

E_SERVER_MSG_TYPE_E_MST_START_C2L_ENUM.name = "e_mst_start_c2l"
E_SERVER_MSG_TYPE_E_MST_START_C2L_ENUM.index = 0
E_SERVER_MSG_TYPE_E_MST_START_C2L_ENUM.number = 10000
E_SERVER_MSG_TYPE_E_MST_C2L_ENTER_ROOM_ENUM.name = "e_mst_c2l_enter_room"
E_SERVER_MSG_TYPE_E_MST_C2L_ENTER_ROOM_ENUM.index = 1
E_SERVER_MSG_TYPE_E_MST_C2L_ENTER_ROOM_ENUM.number = 10001
E_SERVER_MSG_TYPE_E_MST_C2L_GET_ROOM_SCENE_INFO_ENUM.name = "e_mst_c2l_get_room_scene_info"
E_SERVER_MSG_TYPE_E_MST_C2L_GET_ROOM_SCENE_INFO_ENUM.index = 2
E_SERVER_MSG_TYPE_E_MST_C2L_GET_ROOM_SCENE_INFO_ENUM.number = 10002
E_SERVER_MSG_TYPE_E_MST_C2L_CHECK_STATE_ENUM.name = "e_mst_c2l_check_state"
E_SERVER_MSG_TYPE_E_MST_C2L_CHECK_STATE_ENUM.index = 3
E_SERVER_MSG_TYPE_E_MST_C2L_CHECK_STATE_ENUM.number = 10003
E_SERVER_MSG_TYPE_E_MST_C2L_LEAVE_ROOM_ENUM.name = "e_mst_c2l_leave_room"
E_SERVER_MSG_TYPE_E_MST_C2L_LEAVE_ROOM_ENUM.index = 4
E_SERVER_MSG_TYPE_E_MST_C2L_LEAVE_ROOM_ENUM.number = 10004
E_SERVER_MSG_TYPE_E_MST_C2L_ROB_LANDLORD_ENUM.name = "e_mst_c2l_rob_landlord"
E_SERVER_MSG_TYPE_E_MST_C2L_ROB_LANDLORD_ENUM.index = 5
E_SERVER_MSG_TYPE_E_MST_C2L_ROB_LANDLORD_ENUM.number = 10005
E_SERVER_MSG_TYPE_E_MST_C2L_PLAYHAND_ENUM.name = "e_mst_c2l_playhand"
E_SERVER_MSG_TYPE_E_MST_C2L_PLAYHAND_ENUM.index = 6
E_SERVER_MSG_TYPE_E_MST_C2L_PLAYHAND_ENUM.number = 10006
E_SERVER_MSG_TYPE_E_MST_C2L_START_MATCH_ENUM.name = "e_mst_c2l_start_match"
E_SERVER_MSG_TYPE_E_MST_C2L_START_MATCH_ENUM.index = 7
E_SERVER_MSG_TYPE_E_MST_C2L_START_MATCH_ENUM.number = 10007
E_SERVER_MSG_TYPE_E_MST_C2L_HANG_ENUM.name = "e_mst_c2l_Hang"
E_SERVER_MSG_TYPE_E_MST_C2L_HANG_ENUM.index = 8
E_SERVER_MSG_TYPE_E_MST_C2L_HANG_ENUM.number = 10008
E_SERVER_MSG_TYPE_E_MST_C2L_SYSTEMTALK_ENUM.name = "e_mst_c2l_SystemTalk"
E_SERVER_MSG_TYPE_E_MST_C2L_SYSTEMTALK_ENUM.index = 9
E_SERVER_MSG_TYPE_E_MST_C2L_SYSTEMTALK_ENUM.number = 10009
E_SERVER_MSG_TYPE_E_MST_C2L_ROOMLIST_ENUM.name = "e_mst_c2l_roomlist"
E_SERVER_MSG_TYPE_E_MST_C2L_ROOMLIST_ENUM.index = 10
E_SERVER_MSG_TYPE_E_MST_C2L_ROOMLIST_ENUM.number = 10010
E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM.name = "e_mst_start_l2c"
E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM.index = 11
E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM.number = 15000
E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM.name = "e_mst_l2c_enter_room"
E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM.index = 12
E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM.number = 15001
E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM.name = "e_mst_l2c_get_room_scene_info"
E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM.index = 13
E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM.number = 15002
E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM.name = "e_mst_l2c_check_state"
E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM.index = 14
E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM.number = 15003
E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM.name = "e_mst_l2c_leave_room"
E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM.index = 15
E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM.number = 15004
E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM.name = "e_mst_l2c_start_match_result"
E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM.index = 16
E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM.number = 15005
E_SERVER_MSG_TYPE_E_MST_L2C_HANG_ENUM.name = "e_mst_l2c_Hang"
E_SERVER_MSG_TYPE_E_MST_L2C_HANG_ENUM.index = 17
E_SERVER_MSG_TYPE_E_MST_L2C_HANG_ENUM.number = 15006
E_SERVER_MSG_TYPE_E_MST_L2C_ROOMLIST_ENUM.name = "e_mst_l2c_roomlist"
E_SERVER_MSG_TYPE_E_MST_L2C_ROOMLIST_ENUM.index = 18
E_SERVER_MSG_TYPE_E_MST_L2C_ROOMLIST_ENUM.number = 15007
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM.name = "e_mst_l2c_notice_startgame"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM.index = 19
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM.number = 15101
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM.name = "e_mst_l2c_notice_playhand"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM.index = 20
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM.number = 15102
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM.name = "e_mst_l2c_notice_rob_landlord"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM.index = 21
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM.number = 15103
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM.name = "e_mst_l2c_notice_winlose"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM.index = 22
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM.number = 15104
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM.name = "e_mst_l2c_notice_rob_landlord_result"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM.index = 23
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM.number = 15105
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WHO_PLAYHAND_ENUM.name = "e_mst_l2c_notice_who_playhand"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WHO_PLAYHAND_ENUM.index = 24
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WHO_PLAYHAND_ENUM.number = 15106
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_SYSTEMTALK_ENUM.name = "e_mst_l2c_notice_SystemTalk"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_SYSTEMTALK_ENUM.index = 25
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_SYSTEMTALK_ENUM.number = 15107
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_ENTER_LEAVE_INFO_ENUM.name = "e_mst_l2c_notice_room_enter_leave_info"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_ENTER_LEAVE_INFO_ENUM.index = 26
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_ENTER_LEAVE_INFO_ENUM.number = 15108
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_PREPARE_INFO_ENUM.name = "e_mst_l2c_notice_room_prepare_info"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_PREPARE_INFO_ENUM.index = 27
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_PREPARE_INFO_ENUM.number = 15109
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_CHANGE_INFO_ENUM.name = "e_mst_l2c_notice_room_change_info"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_CHANGE_INFO_ENUM.index = 28
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_CHANGE_INFO_ENUM.number = 15110
E_SERVER_MSG_TYPE_E_MST_CLEND_INDEX_ENUM.name = "e_mst_clend_index"
E_SERVER_MSG_TYPE_E_MST_CLEND_INDEX_ENUM.index = 29
E_SERVER_MSG_TYPE_E_MST_CLEND_INDEX_ENUM.number = 20000
E_SERVER_MSG_TYPE.name = "e_server_msg_type"
E_SERVER_MSG_TYPE.full_name = ".game_landlord_net_protocol.e_server_msg_type"
E_SERVER_MSG_TYPE.values = {E_SERVER_MSG_TYPE_E_MST_START_C2L_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_ENTER_ROOM_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_GET_ROOM_SCENE_INFO_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_CHECK_STATE_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_LEAVE_ROOM_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_ROB_LANDLORD_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_PLAYHAND_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_START_MATCH_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_HANG_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_SYSTEMTALK_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_ROOMLIST_ENUM,E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_HANG_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_ROOMLIST_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WHO_PLAYHAND_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_SYSTEMTALK_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_ENTER_LEAVE_INFO_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_PREPARE_INFO_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROOM_CHANGE_INFO_ENUM,E_SERVER_MSG_TYPE_E_MST_CLEND_INDEX_ENUM}
E_SERVER_ERROR_CODE_E_ERROR_CODE_SUCCESS_ENUM.name = "e_error_code_success"
E_SERVER_ERROR_CODE_E_ERROR_CODE_SUCCESS_ENUM.index = 0
E_SERVER_ERROR_CODE_E_ERROR_CODE_SUCCESS_ENUM.number = 1
E_SERVER_ERROR_CODE_E_ERROR_CODE_FAILED_ENUM.name = "e_error_code_failed"
E_SERVER_ERROR_CODE_E_ERROR_CODE_FAILED_ENUM.index = 1
E_SERVER_ERROR_CODE_E_ERROR_CODE_FAILED_ENUM.number = 2
E_SERVER_ERROR_CODE_E_ERROR_CODE_NOT_ENOUGH_MONEY_ENUM.name = "e_error_code_not_enough_money"
E_SERVER_ERROR_CODE_E_ERROR_CODE_NOT_ENOUGH_MONEY_ENUM.index = 2
E_SERVER_ERROR_CODE_E_ERROR_CODE_NOT_ENOUGH_MONEY_ENUM.number = 3
E_SERVER_ERROR_CODE.name = "e_server_error_code"
E_SERVER_ERROR_CODE.full_name = ".game_landlord_net_protocol.e_server_error_code"
E_SERVER_ERROR_CODE.values = {E_SERVER_ERROR_CODE_E_ERROR_CODE_SUCCESS_ENUM,E_SERVER_ERROR_CODE_E_ERROR_CODE_FAILED_ENUM,E_SERVER_ERROR_CODE_E_ERROR_CODE_NOT_ENOUGH_MONEY_ENUM}
E_GAME_STATE_E_GAME_STATE_NONE_ENUM.name = "e_game_state_none"
E_GAME_STATE_E_GAME_STATE_NONE_ENUM.index = 0
E_GAME_STATE_E_GAME_STATE_NONE_ENUM.number = 0
E_GAME_STATE_E_GAME_STATE_MATCHING_ENUM.name = "e_game_state_matching"
E_GAME_STATE_E_GAME_STATE_MATCHING_ENUM.index = 1
E_GAME_STATE_E_GAME_STATE_MATCHING_ENUM.number = 1
E_GAME_STATE_E_GAME_STATE_STARTGAME_ENUM.name = "e_game_state_startgame"
E_GAME_STATE_E_GAME_STATE_STARTGAME_ENUM.index = 2
E_GAME_STATE_E_GAME_STATE_STARTGAME_ENUM.number = 2
E_GAME_STATE_E_GAME_STATE_SENDCARDING_ENUM.name = "e_game_state_sendcarding"
E_GAME_STATE_E_GAME_STATE_SENDCARDING_ENUM.index = 3
E_GAME_STATE_E_GAME_STATE_SENDCARDING_ENUM.number = 3
E_GAME_STATE_E_GAME_STATE_ROBLANDLORE_ENUM.name = "e_game_state_robLandlore"
E_GAME_STATE_E_GAME_STATE_ROBLANDLORE_ENUM.index = 4
E_GAME_STATE_E_GAME_STATE_ROBLANDLORE_ENUM.number = 4
E_GAME_STATE_E_GAME_STATE_PLAYHAND_ENUM.name = "e_game_state_playhand"
E_GAME_STATE_E_GAME_STATE_PLAYHAND_ENUM.index = 5
E_GAME_STATE_E_GAME_STATE_PLAYHAND_ENUM.number = 5
E_GAME_STATE_E_GAME_STATE_AWARD_ENUM.name = "e_game_state_award"
E_GAME_STATE_E_GAME_STATE_AWARD_ENUM.index = 6
E_GAME_STATE_E_GAME_STATE_AWARD_ENUM.number = 6
E_GAME_STATE.name = "e_game_state"
E_GAME_STATE.full_name = ".game_landlord_net_protocol.e_game_state"
E_GAME_STATE.values = {E_GAME_STATE_E_GAME_STATE_NONE_ENUM,E_GAME_STATE_E_GAME_STATE_MATCHING_ENUM,E_GAME_STATE_E_GAME_STATE_STARTGAME_ENUM,E_GAME_STATE_E_GAME_STATE_SENDCARDING_ENUM,E_GAME_STATE_E_GAME_STATE_ROBLANDLORE_ENUM,E_GAME_STATE_E_GAME_STATE_PLAYHAND_ENUM,E_GAME_STATE_E_GAME_STATE_AWARD_ENUM}
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_NONE_ENUM.name = "e_player_game_state_none"
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_NONE_ENUM.index = 0
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_NONE_ENUM.number = 0
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_MATCHING_ENUM.name = "e_player_game_state_matching"
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_MATCHING_ENUM.index = 1
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_MATCHING_ENUM.number = 1
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_SENDCARDING_ENUM.name = "e_player_game_state_sendcarding"
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_SENDCARDING_ENUM.index = 2
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_SENDCARDING_ENUM.number = 2
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_ROBLANDLORD_ENUM.name = "e_player_game_state_robLandlord"
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_ROBLANDLORD_ENUM.index = 3
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_ROBLANDLORD_ENUM.number = 3
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_ROBLANDLORD_ENUM.name = "e_player_game_state_other_robLandlord"
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_ROBLANDLORD_ENUM.index = 4
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_ROBLANDLORD_ENUM.number = 4
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_PLAYHANDING_ENUM.name = "e_player_game_state_playhanding"
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_PLAYHANDING_ENUM.index = 5
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_PLAYHANDING_ENUM.number = 5
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_PLAYHANDING_ENUM.name = "e_player_game_state_other_playhanding"
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_PLAYHANDING_ENUM.index = 6
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_PLAYHANDING_ENUM.number = 6
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_AWARDING_ENUM.name = "e_player_game_state_awarding"
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_AWARDING_ENUM.index = 7
E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_AWARDING_ENUM.number = 7
E_PLAYER_GAME_STATE.name = "e_player_game_state"
E_PLAYER_GAME_STATE.full_name = ".game_landlord_net_protocol.e_player_game_state"
E_PLAYER_GAME_STATE.values = {E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_NONE_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_MATCHING_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_SENDCARDING_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_ROBLANDLORD_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_ROBLANDLORD_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_PLAYHANDING_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_PLAYHANDING_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_AWARDING_ENUM}
CARD_INFO_DESKID_FIELD.name = "deskId"
CARD_INFO_DESKID_FIELD.full_name = ".game_landlord_net_protocol.card_Info.deskId"
CARD_INFO_DESKID_FIELD.number = 1
CARD_INFO_DESKID_FIELD.index = 0
CARD_INFO_DESKID_FIELD.label = 1
CARD_INFO_DESKID_FIELD.has_default_value = false
CARD_INFO_DESKID_FIELD.default_value = 0
CARD_INFO_DESKID_FIELD.type = 5
CARD_INFO_DESKID_FIELD.cpp_type = 1

CARD_INFO_CARDS_FIELD.name = "cards"
CARD_INFO_CARDS_FIELD.full_name = ".game_landlord_net_protocol.card_Info.cards"
CARD_INFO_CARDS_FIELD.number = 2
CARD_INFO_CARDS_FIELD.index = 1
CARD_INFO_CARDS_FIELD.label = 3
CARD_INFO_CARDS_FIELD.has_default_value = false
CARD_INFO_CARDS_FIELD.default_value = {}
CARD_INFO_CARDS_FIELD.type = 5
CARD_INFO_CARDS_FIELD.cpp_type = 1

CARD_INFO.name = "card_Info"
CARD_INFO.full_name = ".game_landlord_net_protocol.card_Info"
CARD_INFO.nested_types = {}
CARD_INFO.enum_types = {}
CARD_INFO.fields = {CARD_INFO_DESKID_FIELD, CARD_INFO_CARDS_FIELD}
CARD_INFO.is_extendable = false
CARD_INFO.extensions = {}
CARD_INFO_1_DESKID_FIELD.name = "deskId"
CARD_INFO_1_DESKID_FIELD.full_name = ".game_landlord_net_protocol.card_Info_1.deskId"
CARD_INFO_1_DESKID_FIELD.number = 1
CARD_INFO_1_DESKID_FIELD.index = 0
CARD_INFO_1_DESKID_FIELD.label = 1
CARD_INFO_1_DESKID_FIELD.has_default_value = false
CARD_INFO_1_DESKID_FIELD.default_value = 0
CARD_INFO_1_DESKID_FIELD.type = 5
CARD_INFO_1_DESKID_FIELD.cpp_type = 1

CARD_INFO_1_CARDS_COUNT_FIELD.name = "cards_count"
CARD_INFO_1_CARDS_COUNT_FIELD.full_name = ".game_landlord_net_protocol.card_Info_1.cards_count"
CARD_INFO_1_CARDS_COUNT_FIELD.number = 2
CARD_INFO_1_CARDS_COUNT_FIELD.index = 1
CARD_INFO_1_CARDS_COUNT_FIELD.label = 1
CARD_INFO_1_CARDS_COUNT_FIELD.has_default_value = false
CARD_INFO_1_CARDS_COUNT_FIELD.default_value = 0
CARD_INFO_1_CARDS_COUNT_FIELD.type = 5
CARD_INFO_1_CARDS_COUNT_FIELD.cpp_type = 1

CARD_INFO_1.name = "card_Info_1"
CARD_INFO_1.full_name = ".game_landlord_net_protocol.card_Info_1"
CARD_INFO_1.nested_types = {}
CARD_INFO_1.enum_types = {}
CARD_INFO_1.fields = {CARD_INFO_1_DESKID_FIELD, CARD_INFO_1_CARDS_COUNT_FIELD}
CARD_INFO_1.is_extendable = false
CARD_INFO_1.extensions = {}
DESK_AWARD_INFO_DESKID_FIELD.name = "deskId"
DESK_AWARD_INFO_DESKID_FIELD.full_name = ".game_landlord_net_protocol.desk_award_Info.deskId"
DESK_AWARD_INFO_DESKID_FIELD.number = 1
DESK_AWARD_INFO_DESKID_FIELD.index = 0
DESK_AWARD_INFO_DESKID_FIELD.label = 1
DESK_AWARD_INFO_DESKID_FIELD.has_default_value = false
DESK_AWARD_INFO_DESKID_FIELD.default_value = 0
DESK_AWARD_INFO_DESKID_FIELD.type = 5
DESK_AWARD_INFO_DESKID_FIELD.cpp_type = 1

DESK_AWARD_INFO_WIN_COUNT_FIELD.name = "win_count"
DESK_AWARD_INFO_WIN_COUNT_FIELD.full_name = ".game_landlord_net_protocol.desk_award_Info.win_count"
DESK_AWARD_INFO_WIN_COUNT_FIELD.number = 2
DESK_AWARD_INFO_WIN_COUNT_FIELD.index = 1
DESK_AWARD_INFO_WIN_COUNT_FIELD.label = 1
DESK_AWARD_INFO_WIN_COUNT_FIELD.has_default_value = false
DESK_AWARD_INFO_WIN_COUNT_FIELD.default_value = 0
DESK_AWARD_INFO_WIN_COUNT_FIELD.type = 5
DESK_AWARD_INFO_WIN_COUNT_FIELD.cpp_type = 1

DESK_AWARD_INFO.name = "desk_award_Info"
DESK_AWARD_INFO.full_name = ".game_landlord_net_protocol.desk_award_Info"
DESK_AWARD_INFO.nested_types = {}
DESK_AWARD_INFO.enum_types = {}
DESK_AWARD_INFO.fields = {DESK_AWARD_INFO_DESKID_FIELD, DESK_AWARD_INFO_WIN_COUNT_FIELD}
DESK_AWARD_INFO.is_extendable = false
DESK_AWARD_INFO.extensions = {}
PLAYER_INFO_PLAYER_ID_FIELD.name = "player_id"
PLAYER_INFO_PLAYER_ID_FIELD.full_name = ".game_landlord_net_protocol.player_info.player_id"
PLAYER_INFO_PLAYER_ID_FIELD.number = 1
PLAYER_INFO_PLAYER_ID_FIELD.index = 0
PLAYER_INFO_PLAYER_ID_FIELD.label = 1
PLAYER_INFO_PLAYER_ID_FIELD.has_default_value = false
PLAYER_INFO_PLAYER_ID_FIELD.default_value = 0
PLAYER_INFO_PLAYER_ID_FIELD.type = 5
PLAYER_INFO_PLAYER_ID_FIELD.cpp_type = 1

PLAYER_INFO_PLAYER_NICKNAME_FIELD.name = "player_nickname"
PLAYER_INFO_PLAYER_NICKNAME_FIELD.full_name = ".game_landlord_net_protocol.player_info.player_nickname"
PLAYER_INFO_PLAYER_NICKNAME_FIELD.number = 2
PLAYER_INFO_PLAYER_NICKNAME_FIELD.index = 1
PLAYER_INFO_PLAYER_NICKNAME_FIELD.label = 1
PLAYER_INFO_PLAYER_NICKNAME_FIELD.has_default_value = false
PLAYER_INFO_PLAYER_NICKNAME_FIELD.default_value = ""
PLAYER_INFO_PLAYER_NICKNAME_FIELD.type = 9
PLAYER_INFO_PLAYER_NICKNAME_FIELD.cpp_type = 9

PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD.name = "player_head_frame"
PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD.full_name = ".game_landlord_net_protocol.player_info.player_head_frame"
PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD.number = 3
PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD.index = 2
PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD.label = 1
PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD.has_default_value = false
PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD.default_value = 0
PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD.type = 5
PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD.cpp_type = 1

PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD.name = "player_head_custom"
PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD.full_name = ".game_landlord_net_protocol.player_info.player_head_custom"
PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD.number = 4
PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD.index = 3
PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD.label = 1
PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD.has_default_value = false
PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD.default_value = ""
PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD.type = 9
PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD.cpp_type = 9

PLAYER_INFO_PLAYER_GOLD_FIELD.name = "player_gold"
PLAYER_INFO_PLAYER_GOLD_FIELD.full_name = ".game_landlord_net_protocol.player_info.player_gold"
PLAYER_INFO_PLAYER_GOLD_FIELD.number = 5
PLAYER_INFO_PLAYER_GOLD_FIELD.index = 4
PLAYER_INFO_PLAYER_GOLD_FIELD.label = 1
PLAYER_INFO_PLAYER_GOLD_FIELD.has_default_value = false
PLAYER_INFO_PLAYER_GOLD_FIELD.default_value = 0
PLAYER_INFO_PLAYER_GOLD_FIELD.type = 3
PLAYER_INFO_PLAYER_GOLD_FIELD.cpp_type = 2

PLAYER_INFO_PLAYER_SEX_FIELD.name = "player_sex"
PLAYER_INFO_PLAYER_SEX_FIELD.full_name = ".game_landlord_net_protocol.player_info.player_sex"
PLAYER_INFO_PLAYER_SEX_FIELD.number = 6
PLAYER_INFO_PLAYER_SEX_FIELD.index = 5
PLAYER_INFO_PLAYER_SEX_FIELD.label = 1
PLAYER_INFO_PLAYER_SEX_FIELD.has_default_value = false
PLAYER_INFO_PLAYER_SEX_FIELD.default_value = 0
PLAYER_INFO_PLAYER_SEX_FIELD.type = 5
PLAYER_INFO_PLAYER_SEX_FIELD.cpp_type = 1

PLAYER_INFO_PLAYER_VIP_LV_FIELD.name = "player_vip_lv"
PLAYER_INFO_PLAYER_VIP_LV_FIELD.full_name = ".game_landlord_net_protocol.player_info.player_vip_lv"
PLAYER_INFO_PLAYER_VIP_LV_FIELD.number = 7
PLAYER_INFO_PLAYER_VIP_LV_FIELD.index = 6
PLAYER_INFO_PLAYER_VIP_LV_FIELD.label = 1
PLAYER_INFO_PLAYER_VIP_LV_FIELD.has_default_value = false
PLAYER_INFO_PLAYER_VIP_LV_FIELD.default_value = 0
PLAYER_INFO_PLAYER_VIP_LV_FIELD.type = 5
PLAYER_INFO_PLAYER_VIP_LV_FIELD.cpp_type = 1

PLAYER_INFO_DESKID_FIELD.name = "deskId"
PLAYER_INFO_DESKID_FIELD.full_name = ".game_landlord_net_protocol.player_info.deskId"
PLAYER_INFO_DESKID_FIELD.number = 8
PLAYER_INFO_DESKID_FIELD.index = 7
PLAYER_INFO_DESKID_FIELD.label = 1
PLAYER_INFO_DESKID_FIELD.has_default_value = false
PLAYER_INFO_DESKID_FIELD.default_value = 0
PLAYER_INFO_DESKID_FIELD.type = 5
PLAYER_INFO_DESKID_FIELD.cpp_type = 1

PLAYER_INFO_ORPREPARE_FIELD.name = "orPrepare"
PLAYER_INFO_ORPREPARE_FIELD.full_name = ".game_landlord_net_protocol.player_info.orPrepare"
PLAYER_INFO_ORPREPARE_FIELD.number = 9
PLAYER_INFO_ORPREPARE_FIELD.index = 8
PLAYER_INFO_ORPREPARE_FIELD.label = 1
PLAYER_INFO_ORPREPARE_FIELD.has_default_value = false
PLAYER_INFO_ORPREPARE_FIELD.default_value = false
PLAYER_INFO_ORPREPARE_FIELD.type = 8
PLAYER_INFO_ORPREPARE_FIELD.cpp_type = 7

PLAYER_INFO.name = "player_info"
PLAYER_INFO.full_name = ".game_landlord_net_protocol.player_info"
PLAYER_INFO.nested_types = {}
PLAYER_INFO.enum_types = {}
PLAYER_INFO.fields = {PLAYER_INFO_PLAYER_ID_FIELD, PLAYER_INFO_PLAYER_NICKNAME_FIELD, PLAYER_INFO_PLAYER_HEAD_FRAME_FIELD, PLAYER_INFO_PLAYER_HEAD_CUSTOM_FIELD, PLAYER_INFO_PLAYER_GOLD_FIELD, PLAYER_INFO_PLAYER_SEX_FIELD, PLAYER_INFO_PLAYER_VIP_LV_FIELD, PLAYER_INFO_DESKID_FIELD, PLAYER_INFO_ORPREPARE_FIELD}
PLAYER_INFO.is_extendable = false
PLAYER_INFO.extensions = {}
ROOM_INFO_ROOM_ID_FIELD.name = "room_id"
ROOM_INFO_ROOM_ID_FIELD.full_name = ".game_landlord_net_protocol.room_info.room_id"
ROOM_INFO_ROOM_ID_FIELD.number = 1
ROOM_INFO_ROOM_ID_FIELD.index = 0
ROOM_INFO_ROOM_ID_FIELD.label = 1
ROOM_INFO_ROOM_ID_FIELD.has_default_value = false
ROOM_INFO_ROOM_ID_FIELD.default_value = 0
ROOM_INFO_ROOM_ID_FIELD.type = 5
ROOM_INFO_ROOM_ID_FIELD.cpp_type = 1

ROOM_INFO_PLAYER_COUNT_FIELD.name = "player_count"
ROOM_INFO_PLAYER_COUNT_FIELD.full_name = ".game_landlord_net_protocol.room_info.player_count"
ROOM_INFO_PLAYER_COUNT_FIELD.number = 2
ROOM_INFO_PLAYER_COUNT_FIELD.index = 1
ROOM_INFO_PLAYER_COUNT_FIELD.label = 1
ROOM_INFO_PLAYER_COUNT_FIELD.has_default_value = false
ROOM_INFO_PLAYER_COUNT_FIELD.default_value = 0
ROOM_INFO_PLAYER_COUNT_FIELD.type = 5
ROOM_INFO_PLAYER_COUNT_FIELD.cpp_type = 1

ROOM_INFO_ROOM_STATE_FIELD.name = "room_state"
ROOM_INFO_ROOM_STATE_FIELD.full_name = ".game_landlord_net_protocol.room_info.room_state"
ROOM_INFO_ROOM_STATE_FIELD.number = 3
ROOM_INFO_ROOM_STATE_FIELD.index = 2
ROOM_INFO_ROOM_STATE_FIELD.label = 1
ROOM_INFO_ROOM_STATE_FIELD.has_default_value = false
ROOM_INFO_ROOM_STATE_FIELD.default_value = 0
ROOM_INFO_ROOM_STATE_FIELD.type = 5
ROOM_INFO_ROOM_STATE_FIELD.cpp_type = 1

ROOM_INFO.name = "room_info"
ROOM_INFO.full_name = ".game_landlord_net_protocol.room_info"
ROOM_INFO.nested_types = {}
ROOM_INFO.enum_types = {}
ROOM_INFO.fields = {ROOM_INFO_ROOM_ID_FIELD, ROOM_INFO_PLAYER_COUNT_FIELD, ROOM_INFO_ROOM_STATE_FIELD}
ROOM_INFO.is_extendable = false
ROOM_INFO.extensions = {}

card_Info = protobuf.Message(CARD_INFO)
card_Info_1 = protobuf.Message(CARD_INFO_1)
desk_award_Info = protobuf.Message(DESK_AWARD_INFO)
e_error_code_failed = 2
e_error_code_not_enough_money = 3
e_error_code_success = 1
e_game_state_award = 6
e_game_state_matching = 1
e_game_state_none = 0
e_game_state_playhand = 5
e_game_state_robLandlore = 4
e_game_state_sendcarding = 3
e_game_state_startgame = 2
e_mst_c2l_Hang = 10008
e_mst_c2l_SystemTalk = 10009
e_mst_c2l_check_state = 10003
e_mst_c2l_enter_room = 10001
e_mst_c2l_get_room_scene_info = 10002
e_mst_c2l_leave_room = 10004
e_mst_c2l_playhand = 10006
e_mst_c2l_rob_landlord = 10005
e_mst_c2l_roomlist = 10010
e_mst_c2l_start_match = 10007
e_mst_clend_index = 20000
e_mst_l2c_Hang = 15006
e_mst_l2c_check_state = 15003
e_mst_l2c_enter_room = 15001
e_mst_l2c_get_room_scene_info = 15002
e_mst_l2c_leave_room = 15004
e_mst_l2c_notice_SystemTalk = 15107
e_mst_l2c_notice_playhand = 15102
e_mst_l2c_notice_rob_landlord = 15103
e_mst_l2c_notice_rob_landlord_result = 15105
e_mst_l2c_notice_room_change_info = 15110
e_mst_l2c_notice_room_enter_leave_info = 15108
e_mst_l2c_notice_room_prepare_info = 15109
e_mst_l2c_notice_startgame = 15101
e_mst_l2c_notice_who_playhand = 15106
e_mst_l2c_notice_winlose = 15104
e_mst_l2c_roomlist = 15007
e_mst_l2c_start_match_result = 15005
e_mst_start_c2l = 10000
e_mst_start_l2c = 15000
e_player_game_state_awarding = 7
e_player_game_state_matching = 1
e_player_game_state_none = 0
e_player_game_state_other_playhanding = 6
e_player_game_state_other_robLandlord = 4
e_player_game_state_playhanding = 5
e_player_game_state_robLandlord = 3
e_player_game_state_sendcarding = 2
player_info = protobuf.Message(PLAYER_INFO)
room_info = protobuf.Message(ROOM_INFO)

