# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: Message2Server.proto
"""Generated protocol buffer code."""
import MessageType_pb2 as MessageType__pb2
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x14Message2Server.proto\x12\x08protobuf\x1a\x11MessageType.proto\"\xaf\x01\n\tPlayerMsg\x12\x11\n\tplayer_id\x18\x01 \x01(\x03\x12)\n\x0bplayer_type\x18\x02 \x01(\x0e\x32\x14.protobuf.PlayerType\x12)\n\nhuman_type\x18\x03 \x01(\x0e\x32\x13.protobuf.HumanTypeH\x00\x12-\n\x0c\x62utcher_type\x18\x04 \x01(\x0e\x32\x15.protobuf.ButcherTypeH\x00\x42\n\n\x08job_type\"I\n\x07MoveMsg\x12\x11\n\tplayer_id\x18\x01 \x01(\x03\x12\r\n\x05\x61ngle\x18\x02 \x01(\x01\x12\x1c\n\x14time_in_milliseconds\x18\x03 \x01(\x03\"C\n\x07PickMsg\x12\x11\n\tplayer_id\x18\x01 \x01(\x03\x12%\n\tprop_type\x18\x02 \x01(\x0e\x32\x12.protobuf.PropType\"C\n\x07SendMsg\x12\x11\n\tplayer_id\x18\x01 \x01(\x03\x12\x14\n\x0cto_player_id\x18\x02 \x01(\x03\x12\x0f\n\x07message\x18\x03 \x01(\t\"-\n\tAttackMsg\x12\x11\n\tplayer_id\x18\x01 \x01(\x03\x12\r\n\x05\x61ngle\x18\x02 \x01(\x01\"\x1a\n\x05IDMsg\x12\x11\n\tplayer_id\x18\x01 \x01(\x03\x62\x06proto3')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(
    DESCRIPTOR, 'Message2Server_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

    DESCRIPTOR._options = None
    _PLAYERMSG._serialized_start = 54
    _PLAYERMSG._serialized_end = 229
    _MOVEMSG._serialized_start = 231
    _MOVEMSG._serialized_end = 304
    _PICKMSG._serialized_start = 306
    _PICKMSG._serialized_end = 373
    _SENDMSG._serialized_start = 375
    _SENDMSG._serialized_end = 442
    _ATTACKMSG._serialized_start = 444
    _ATTACKMSG._serialized_end = 489
    _IDMSG._serialized_start = 491
    _IDMSG._serialized_end = 517
# @@protoc_insertion_point(module_scope)
