// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: client2logic_protocol.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "client2logic_protocol.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace client2logic_protocols {

namespace {


}  // namespace


void protobuf_AssignDesc_client2logic_5fprotocol_2eproto() {
  protobuf_AddDesc_client2logic_5fprotocol_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "client2logic_protocol.proto");
  GOOGLE_CHECK(file != NULL);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_client2logic_5fprotocol_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_client2logic_5fprotocol_2eproto() {
}

void protobuf_AddDesc_client2logic_5fprotocol_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::client2logic_protocols::protobuf_AddDesc_client2logic_5fmsg_5ftype_2eproto();
  ::msg_type_def::protobuf_AddDesc_msg_5ftype_5fdef_2eproto();
  ::msg_info_def::protobuf_AddDesc_msg_5finfo_5fdef_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\033client2logic_protocol.proto\022\026client2lo"
    "gic_protocols\032\033client2logic_msg_type.pro"
    "to\032\022msg_type_def.proto\032\022msg_info_def.pro"
    "to", 122);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "client2logic_protocol.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_client2logic_5fprotocol_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_client2logic_5fprotocol_2eproto {
  StaticDescriptorInitializer_client2logic_5fprotocol_2eproto() {
    protobuf_AddDesc_client2logic_5fprotocol_2eproto();
  }
} static_descriptor_initializer_client2logic_5fprotocol_2eproto_;

// @@protoc_insertion_point(namespace_scope)

}  // namespace client2logic_protocols

// @@protoc_insertion_point(global_scope)
