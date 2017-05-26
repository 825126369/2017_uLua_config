-- Generated By protoc-gen-lua Do not Edit
local protobuf = require "protobuf/protobuf"
module('game_landlord_def_pb')


E_SERVER_MSG_TYPE = protobuf.EnumDescriptor();
E_SERVER_MSG_TYPE_E_MST_START_C2L_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_ENTER_ROOM_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_GET_ROOM_SCENE_INFO_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_CHECK_STATE_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_LEAVE_ROOM_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_ROB_LANDLORD_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_PLAYHAND_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_C2L_START_MATCH_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_PLAYHAND_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM = protobuf.EnumValueDescriptor();
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM = protobuf.EnumValueDescriptor();
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
E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM.name = "e_mst_start_l2c"
E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM.index = 8
E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM.number = 15000
E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM.name = "e_mst_l2c_enter_room"
E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM.index = 9
E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM.number = 15001
E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM.name = "e_mst_l2c_get_room_scene_info"
E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM.index = 10
E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM.number = 15002
E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM.name = "e_mst_l2c_check_state"
E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM.index = 11
E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM.number = 15003
E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM.name = "e_mst_l2c_leave_room"
E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM.index = 12
E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM.number = 15004
E_SERVER_MSG_TYPE_E_MST_L2C_PLAYHAND_ENUM.name = "e_mst_l2c_playhand"
E_SERVER_MSG_TYPE_E_MST_L2C_PLAYHAND_ENUM.index = 13
E_SERVER_MSG_TYPE_E_MST_L2C_PLAYHAND_ENUM.number = 15005
E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM.name = "e_mst_l2c_start_match_result"
E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM.index = 14
E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM.number = 15006
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM.name = "e_mst_l2c_notice_startgame"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM.index = 15
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM.number = 15101
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM.name = "e_mst_l2c_notice_playhand"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM.index = 16
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM.number = 15102
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM.name = "e_mst_l2c_notice_rob_landlord"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM.index = 17
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM.number = 15103
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM.name = "e_mst_l2c_notice_winlose"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM.index = 18
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM.number = 15104
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM.name = "e_mst_l2c_notice_rob_landlord_result"
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM.index = 19
E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM.number = 15105
E_SERVER_MSG_TYPE_E_MST_CLEND_INDEX_ENUM.name = "e_mst_clend_index"
E_SERVER_MSG_TYPE_E_MST_CLEND_INDEX_ENUM.index = 20
E_SERVER_MSG_TYPE_E_MST_CLEND_INDEX_ENUM.number = 20000
E_SERVER_MSG_TYPE.name = "e_server_msg_type"
E_SERVER_MSG_TYPE.full_name = ".game_landlord_protocol.e_server_msg_type"
E_SERVER_MSG_TYPE.values = {E_SERVER_MSG_TYPE_E_MST_START_C2L_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_ENTER_ROOM_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_GET_ROOM_SCENE_INFO_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_CHECK_STATE_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_LEAVE_ROOM_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_ROB_LANDLORD_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_PLAYHAND_ENUM,E_SERVER_MSG_TYPE_E_MST_C2L_START_MATCH_ENUM,E_SERVER_MSG_TYPE_E_MST_START_L2C_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_ENTER_ROOM_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_GET_ROOM_SCENE_INFO_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_CHECK_STATE_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_LEAVE_ROOM_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_PLAYHAND_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_START_MATCH_RESULT_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_STARTGAME_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_PLAYHAND_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_WINLOSE_ENUM,E_SERVER_MSG_TYPE_E_MST_L2C_NOTICE_ROB_LANDLORD_RESULT_ENUM,E_SERVER_MSG_TYPE_E_MST_CLEND_INDEX_ENUM}
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
E_SERVER_ERROR_CODE.full_name = ".game_landlord_protocol.e_server_error_code"
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
E_GAME_STATE.full_name = ".game_landlord_protocol.e_game_state"
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
E_PLAYER_GAME_STATE.full_name = ".game_landlord_protocol.e_player_game_state"
E_PLAYER_GAME_STATE.values = {E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_NONE_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_MATCHING_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_SENDCARDING_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_ROBLANDLORD_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_ROBLANDLORD_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_PLAYHANDING_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_OTHER_PLAYHANDING_ENUM,E_PLAYER_GAME_STATE_E_PLAYER_GAME_STATE_AWARDING_ENUM}

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
e_mst_c2l_check_state = 10003
e_mst_c2l_enter_room = 10001
e_mst_c2l_get_room_scene_info = 10002
e_mst_c2l_leave_room = 10004
e_mst_c2l_playhand = 10006
e_mst_c2l_rob_landlord = 10005
e_mst_c2l_start_match = 10007
e_mst_clend_index = 20000
e_mst_l2c_check_state = 15003
e_mst_l2c_enter_room = 15001
e_mst_l2c_get_room_scene_info = 15002
e_mst_l2c_leave_room = 15004
e_mst_l2c_notice_playhand = 15102
e_mst_l2c_notice_rob_landlord = 15103
e_mst_l2c_notice_rob_landlord_result = 15105
e_mst_l2c_notice_startgame = 15101
e_mst_l2c_notice_winlose = 15104
e_mst_l2c_playhand = 15005
e_mst_l2c_start_match_result = 15006
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

