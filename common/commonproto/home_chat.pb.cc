// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: home_chat.proto

#include "home_chat.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace im_home_proto {
PROTOBUF_CONSTEXPR ChatMessage::ChatMessage(
    ::_pbi::ConstantInitialized)
  : data_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , senderid_(int64_t{0})
  , receiverid_(int64_t{0})
  , messageid_(int64_t{0})
  , sendtimestamp_(int64_t{0})
  , messagetype_(0)

  , messagestatus_(0)
{}
struct ChatMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ChatMessageDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ChatMessageDefaultTypeInternal() {}
  union {
    ChatMessage _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ChatMessageDefaultTypeInternal _ChatMessage_default_instance_;
PROTOBUF_CONSTEXPR ChatSingleReq::ChatSingleReq(
    ::_pbi::ConstantInitialized)
  : data_(nullptr){}
struct ChatSingleReqDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ChatSingleReqDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ChatSingleReqDefaultTypeInternal() {}
  union {
    ChatSingleReq _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ChatSingleReqDefaultTypeInternal _ChatSingleReq_default_instance_;
PROTOBUF_CONSTEXPR ChatSingleRes::ChatSingleRes(
    ::_pbi::ConstantInitialized)
  : data_(nullptr){}
struct ChatSingleResDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ChatSingleResDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ChatSingleResDefaultTypeInternal() {}
  union {
    ChatSingleRes _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ChatSingleResDefaultTypeInternal _ChatSingleRes_default_instance_;
}  // namespace im_home_proto
static ::_pb::Metadata file_level_metadata_home_5fchat_2eproto[3];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_home_5fchat_2eproto[2];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_home_5fchat_2eproto = nullptr;

const uint32_t TableStruct_home_5fchat_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatMessage, senderid_),
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatMessage, receiverid_),
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatMessage, messageid_),
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatMessage, messagetype_),
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatMessage, sendtimestamp_),
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatMessage, messagestatus_),
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatMessage, data_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatSingleReq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatSingleReq, data_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatSingleRes, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ChatSingleRes, data_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::im_home_proto::ChatMessage)},
  { 13, -1, -1, sizeof(::im_home_proto::ChatSingleReq)},
  { 20, -1, -1, sizeof(::im_home_proto::ChatSingleRes)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::im_home_proto::_ChatMessage_default_instance_._instance,
  &::im_home_proto::_ChatSingleReq_default_instance_._instance,
  &::im_home_proto::_ChatSingleRes_default_instance_._instance,
};

const char descriptor_table_protodef_home_5fchat_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017home_chat.proto\022\rim_home_proto\"\333\001\n\013Cha"
  "tMessage\022\020\n\010SenderID\030\001 \001(\003\022\022\n\nReceiverID"
  "\030\002 \001(\003\022\021\n\tMessageID\030\003 \001(\003\0224\n\013MessageType"
  "\030\004 \001(\0162\037.im_home_proto.MessageType_Enum\022"
  "\025\n\rSendTimeStamp\030\005 \001(\003\0228\n\rMessageStatus\030"
  "\006 \001(\0162!.im_home_proto.MessageStatus_Enum"
  "\022\014\n\004Data\030\007 \001(\t\"9\n\rChatSingleReq\022(\n\004Data\030"
  "\001 \001(\0132\032.im_home_proto.ChatMessage\"9\n\rCha"
  "tSingleRes\022(\n\004Data\030\001 \001(\0132\032.im_home_proto"
  ".ChatMessage*e\n\020MessageType_Enum\022\034\n\030Mess"
  "ageType_Enum_Default\020\000\022\020\n\014EnumTextType\020\001"
  "\022\017\n\013EnumImgType\020\002\022\020\n\014EnumFileType\020\003*`\n\022M"
  "essageStatus_Enum\022\036\n\032MessageStatus_Enum_"
  "Default\020\000\022\014\n\010EnumSend\020\001\022\016\n\nEnumArrive\020\002\022"
  "\014\n\010EnumRead\020\003BDZBgithub.com/mimis-s/IM-S"
  "ervice/src/common/commonproto/im_home_pr"
  "otob\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_home_5fchat_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_home_5fchat_2eproto = {
    false, false, 651, descriptor_table_protodef_home_5fchat_2eproto,
    "home_chat.proto",
    &descriptor_table_home_5fchat_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_home_5fchat_2eproto::offsets,
    file_level_metadata_home_5fchat_2eproto, file_level_enum_descriptors_home_5fchat_2eproto,
    file_level_service_descriptors_home_5fchat_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_home_5fchat_2eproto_getter() {
  return &descriptor_table_home_5fchat_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_home_5fchat_2eproto(&descriptor_table_home_5fchat_2eproto);
namespace im_home_proto {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MessageType_Enum_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_home_5fchat_2eproto);
  return file_level_enum_descriptors_home_5fchat_2eproto[0];
}
bool MessageType_Enum_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MessageStatus_Enum_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_home_5fchat_2eproto);
  return file_level_enum_descriptors_home_5fchat_2eproto[1];
}
bool MessageStatus_Enum_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class ChatMessage::_Internal {
 public:
};

ChatMessage::ChatMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:im_home_proto.ChatMessage)
}
ChatMessage::ChatMessage(const ChatMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  data_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    data_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_data().empty()) {
    data_.Set(from._internal_data(), 
      GetArenaForAllocation());
  }
  ::memcpy(&senderid_, &from.senderid_,
    static_cast<size_t>(reinterpret_cast<char*>(&messagestatus_) -
    reinterpret_cast<char*>(&senderid_)) + sizeof(messagestatus_));
  // @@protoc_insertion_point(copy_constructor:im_home_proto.ChatMessage)
}

inline void ChatMessage::SharedCtor() {
data_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  data_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&senderid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&messagestatus_) -
    reinterpret_cast<char*>(&senderid_)) + sizeof(messagestatus_));
}

ChatMessage::~ChatMessage() {
  // @@protoc_insertion_point(destructor:im_home_proto.ChatMessage)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ChatMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  data_.Destroy();
}

void ChatMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ChatMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:im_home_proto.ChatMessage)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.ClearToEmpty();
  ::memset(&senderid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&messagestatus_) -
      reinterpret_cast<char*>(&senderid_)) + sizeof(messagestatus_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ChatMessage::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int64 SenderID = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          senderid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int64 ReceiverID = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          receiverid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int64 MessageID = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          messageid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .im_home_proto.MessageType_Enum MessageType = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_messagetype(static_cast<::im_home_proto::MessageType_Enum>(val));
        } else
          goto handle_unusual;
        continue;
      // int64 SendTimeStamp = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          sendtimestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .im_home_proto.MessageStatus_Enum MessageStatus = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_messagestatus(static_cast<::im_home_proto::MessageStatus_Enum>(val));
        } else
          goto handle_unusual;
        continue;
      // string Data = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          auto str = _internal_mutable_data();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "im_home_proto.ChatMessage.Data"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ChatMessage::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:im_home_proto.ChatMessage)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 SenderID = 1;
  if (this->_internal_senderid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(1, this->_internal_senderid(), target);
  }

  // int64 ReceiverID = 2;
  if (this->_internal_receiverid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(2, this->_internal_receiverid(), target);
  }

  // int64 MessageID = 3;
  if (this->_internal_messageid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(3, this->_internal_messageid(), target);
  }

  // .im_home_proto.MessageType_Enum MessageType = 4;
  if (this->_internal_messagetype() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      4, this->_internal_messagetype(), target);
  }

  // int64 SendTimeStamp = 5;
  if (this->_internal_sendtimestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(5, this->_internal_sendtimestamp(), target);
  }

  // .im_home_proto.MessageStatus_Enum MessageStatus = 6;
  if (this->_internal_messagestatus() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      6, this->_internal_messagestatus(), target);
  }

  // string Data = 7;
  if (!this->_internal_data().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_data().data(), static_cast<int>(this->_internal_data().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "im_home_proto.ChatMessage.Data");
    target = stream->WriteStringMaybeAliased(
        7, this->_internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:im_home_proto.ChatMessage)
  return target;
}

size_t ChatMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:im_home_proto.ChatMessage)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string Data = 7;
  if (!this->_internal_data().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_data());
  }

  // int64 SenderID = 1;
  if (this->_internal_senderid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_senderid());
  }

  // int64 ReceiverID = 2;
  if (this->_internal_receiverid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_receiverid());
  }

  // int64 MessageID = 3;
  if (this->_internal_messageid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_messageid());
  }

  // int64 SendTimeStamp = 5;
  if (this->_internal_sendtimestamp() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_sendtimestamp());
  }

  // .im_home_proto.MessageType_Enum MessageType = 4;
  if (this->_internal_messagetype() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_messagetype());
  }

  // .im_home_proto.MessageStatus_Enum MessageStatus = 6;
  if (this->_internal_messagestatus() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_messagestatus());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ChatMessage::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ChatMessage::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ChatMessage::GetClassData() const { return &_class_data_; }

void ChatMessage::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ChatMessage *>(to)->MergeFrom(
      static_cast<const ChatMessage &>(from));
}


void ChatMessage::MergeFrom(const ChatMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:im_home_proto.ChatMessage)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_data().empty()) {
    _internal_set_data(from._internal_data());
  }
  if (from._internal_senderid() != 0) {
    _internal_set_senderid(from._internal_senderid());
  }
  if (from._internal_receiverid() != 0) {
    _internal_set_receiverid(from._internal_receiverid());
  }
  if (from._internal_messageid() != 0) {
    _internal_set_messageid(from._internal_messageid());
  }
  if (from._internal_sendtimestamp() != 0) {
    _internal_set_sendtimestamp(from._internal_sendtimestamp());
  }
  if (from._internal_messagetype() != 0) {
    _internal_set_messagetype(from._internal_messagetype());
  }
  if (from._internal_messagestatus() != 0) {
    _internal_set_messagestatus(from._internal_messagestatus());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ChatMessage::CopyFrom(const ChatMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:im_home_proto.ChatMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChatMessage::IsInitialized() const {
  return true;
}

void ChatMessage::InternalSwap(ChatMessage* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &data_, lhs_arena,
      &other->data_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ChatMessage, messagestatus_)
      + sizeof(ChatMessage::messagestatus_)
      - PROTOBUF_FIELD_OFFSET(ChatMessage, senderid_)>(
          reinterpret_cast<char*>(&senderid_),
          reinterpret_cast<char*>(&other->senderid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ChatMessage::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_home_5fchat_2eproto_getter, &descriptor_table_home_5fchat_2eproto_once,
      file_level_metadata_home_5fchat_2eproto[0]);
}

// ===================================================================

class ChatSingleReq::_Internal {
 public:
  static const ::im_home_proto::ChatMessage& data(const ChatSingleReq* msg);
};

const ::im_home_proto::ChatMessage&
ChatSingleReq::_Internal::data(const ChatSingleReq* msg) {
  return *msg->data_;
}
ChatSingleReq::ChatSingleReq(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:im_home_proto.ChatSingleReq)
}
ChatSingleReq::ChatSingleReq(const ChatSingleReq& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_data()) {
    data_ = new ::im_home_proto::ChatMessage(*from.data_);
  } else {
    data_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:im_home_proto.ChatSingleReq)
}

inline void ChatSingleReq::SharedCtor() {
data_ = nullptr;
}

ChatSingleReq::~ChatSingleReq() {
  // @@protoc_insertion_point(destructor:im_home_proto.ChatSingleReq)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ChatSingleReq::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete data_;
}

void ChatSingleReq::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ChatSingleReq::Clear() {
// @@protoc_insertion_point(message_clear_start:im_home_proto.ChatSingleReq)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && data_ != nullptr) {
    delete data_;
  }
  data_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ChatSingleReq::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .im_home_proto.ChatMessage Data = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_data(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ChatSingleReq::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:im_home_proto.ChatSingleReq)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .im_home_proto.ChatMessage Data = 1;
  if (this->_internal_has_data()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::data(this),
        _Internal::data(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:im_home_proto.ChatSingleReq)
  return target;
}

size_t ChatSingleReq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:im_home_proto.ChatSingleReq)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .im_home_proto.ChatMessage Data = 1;
  if (this->_internal_has_data()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *data_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ChatSingleReq::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ChatSingleReq::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ChatSingleReq::GetClassData() const { return &_class_data_; }

void ChatSingleReq::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ChatSingleReq *>(to)->MergeFrom(
      static_cast<const ChatSingleReq &>(from));
}


void ChatSingleReq::MergeFrom(const ChatSingleReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:im_home_proto.ChatSingleReq)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_data()) {
    _internal_mutable_data()->::im_home_proto::ChatMessage::MergeFrom(from._internal_data());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ChatSingleReq::CopyFrom(const ChatSingleReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:im_home_proto.ChatSingleReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChatSingleReq::IsInitialized() const {
  return true;
}

void ChatSingleReq::InternalSwap(ChatSingleReq* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(data_, other->data_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ChatSingleReq::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_home_5fchat_2eproto_getter, &descriptor_table_home_5fchat_2eproto_once,
      file_level_metadata_home_5fchat_2eproto[1]);
}

// ===================================================================

class ChatSingleRes::_Internal {
 public:
  static const ::im_home_proto::ChatMessage& data(const ChatSingleRes* msg);
};

const ::im_home_proto::ChatMessage&
ChatSingleRes::_Internal::data(const ChatSingleRes* msg) {
  return *msg->data_;
}
ChatSingleRes::ChatSingleRes(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:im_home_proto.ChatSingleRes)
}
ChatSingleRes::ChatSingleRes(const ChatSingleRes& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_data()) {
    data_ = new ::im_home_proto::ChatMessage(*from.data_);
  } else {
    data_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:im_home_proto.ChatSingleRes)
}

inline void ChatSingleRes::SharedCtor() {
data_ = nullptr;
}

ChatSingleRes::~ChatSingleRes() {
  // @@protoc_insertion_point(destructor:im_home_proto.ChatSingleRes)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ChatSingleRes::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete data_;
}

void ChatSingleRes::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ChatSingleRes::Clear() {
// @@protoc_insertion_point(message_clear_start:im_home_proto.ChatSingleRes)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && data_ != nullptr) {
    delete data_;
  }
  data_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ChatSingleRes::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .im_home_proto.ChatMessage Data = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_data(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ChatSingleRes::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:im_home_proto.ChatSingleRes)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .im_home_proto.ChatMessage Data = 1;
  if (this->_internal_has_data()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::data(this),
        _Internal::data(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:im_home_proto.ChatSingleRes)
  return target;
}

size_t ChatSingleRes::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:im_home_proto.ChatSingleRes)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .im_home_proto.ChatMessage Data = 1;
  if (this->_internal_has_data()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *data_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ChatSingleRes::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ChatSingleRes::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ChatSingleRes::GetClassData() const { return &_class_data_; }

void ChatSingleRes::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ChatSingleRes *>(to)->MergeFrom(
      static_cast<const ChatSingleRes &>(from));
}


void ChatSingleRes::MergeFrom(const ChatSingleRes& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:im_home_proto.ChatSingleRes)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_data()) {
    _internal_mutable_data()->::im_home_proto::ChatMessage::MergeFrom(from._internal_data());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ChatSingleRes::CopyFrom(const ChatSingleRes& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:im_home_proto.ChatSingleRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChatSingleRes::IsInitialized() const {
  return true;
}

void ChatSingleRes::InternalSwap(ChatSingleRes* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(data_, other->data_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ChatSingleRes::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_home_5fchat_2eproto_getter, &descriptor_table_home_5fchat_2eproto_once,
      file_level_metadata_home_5fchat_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace im_home_proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::im_home_proto::ChatMessage*
Arena::CreateMaybeMessage< ::im_home_proto::ChatMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::im_home_proto::ChatMessage >(arena);
}
template<> PROTOBUF_NOINLINE ::im_home_proto::ChatSingleReq*
Arena::CreateMaybeMessage< ::im_home_proto::ChatSingleReq >(Arena* arena) {
  return Arena::CreateMessageInternal< ::im_home_proto::ChatSingleReq >(arena);
}
template<> PROTOBUF_NOINLINE ::im_home_proto::ChatSingleRes*
Arena::CreateMaybeMessage< ::im_home_proto::ChatSingleRes >(Arena* arena) {
  return Arena::CreateMessageInternal< ::im_home_proto::ChatSingleRes >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
