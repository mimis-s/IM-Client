// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: home_message.proto

#include "home_message.pb.h"

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
PROTOBUF_CONSTEXPR GetSingleChatHistoryReq::GetSingleChatHistoryReq(
    ::_pbi::ConstantInitialized)
  : maxnotgainmessageid_(int64_t{0})
  , friendid_(int64_t{0}){}
struct GetSingleChatHistoryReqDefaultTypeInternal {
  PROTOBUF_CONSTEXPR GetSingleChatHistoryReqDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~GetSingleChatHistoryReqDefaultTypeInternal() {}
  union {
    GetSingleChatHistoryReq _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 GetSingleChatHistoryReqDefaultTypeInternal _GetSingleChatHistoryReq_default_instance_;
PROTOBUF_CONSTEXPR GetSingleChatHistoryRes::GetSingleChatHistoryRes(
    ::_pbi::ConstantInitialized)
  : data_()
  , friendid_(int64_t{0}){}
struct GetSingleChatHistoryResDefaultTypeInternal {
  PROTOBUF_CONSTEXPR GetSingleChatHistoryResDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~GetSingleChatHistoryResDefaultTypeInternal() {}
  union {
    GetSingleChatHistoryRes _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 GetSingleChatHistoryResDefaultTypeInternal _GetSingleChatHistoryRes_default_instance_;
PROTOBUF_CONSTEXPR ReadOfflineMessageReq::ReadOfflineMessageReq(
    ::_pbi::ConstantInitialized)
  : friendid_(int64_t{0}){}
struct ReadOfflineMessageReqDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ReadOfflineMessageReqDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ReadOfflineMessageReqDefaultTypeInternal() {}
  union {
    ReadOfflineMessageReq _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ReadOfflineMessageReqDefaultTypeInternal _ReadOfflineMessageReq_default_instance_;
PROTOBUF_CONSTEXPR ReadOfflineMessageRes::ReadOfflineMessageRes(
    ::_pbi::ConstantInitialized)
  : data_()
  , friendid_(int64_t{0}){}
struct ReadOfflineMessageResDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ReadOfflineMessageResDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ReadOfflineMessageResDefaultTypeInternal() {}
  union {
    ReadOfflineMessageRes _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ReadOfflineMessageResDefaultTypeInternal _ReadOfflineMessageRes_default_instance_;
}  // namespace im_home_proto
static ::_pb::Metadata file_level_metadata_home_5fmessage_2eproto[4];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_home_5fmessage_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_home_5fmessage_2eproto = nullptr;

const uint32_t TableStruct_home_5fmessage_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::GetSingleChatHistoryReq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::GetSingleChatHistoryReq, maxnotgainmessageid_),
  PROTOBUF_FIELD_OFFSET(::im_home_proto::GetSingleChatHistoryReq, friendid_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::GetSingleChatHistoryRes, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::GetSingleChatHistoryRes, friendid_),
  PROTOBUF_FIELD_OFFSET(::im_home_proto::GetSingleChatHistoryRes, data_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ReadOfflineMessageReq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ReadOfflineMessageReq, friendid_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ReadOfflineMessageRes, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ReadOfflineMessageRes, friendid_),
  PROTOBUF_FIELD_OFFSET(::im_home_proto::ReadOfflineMessageRes, data_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::im_home_proto::GetSingleChatHistoryReq)},
  { 8, -1, -1, sizeof(::im_home_proto::GetSingleChatHistoryRes)},
  { 16, -1, -1, sizeof(::im_home_proto::ReadOfflineMessageReq)},
  { 23, -1, -1, sizeof(::im_home_proto::ReadOfflineMessageRes)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::im_home_proto::_GetSingleChatHistoryReq_default_instance_._instance,
  &::im_home_proto::_GetSingleChatHistoryRes_default_instance_._instance,
  &::im_home_proto::_ReadOfflineMessageReq_default_instance_._instance,
  &::im_home_proto::_ReadOfflineMessageRes_default_instance_._instance,
};

const char descriptor_table_protodef_home_5fmessage_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022home_message.proto\022\rim_home_proto\032\017hom"
  "e_chat.proto\"H\n\027GetSingleChatHistoryReq\022"
  "\033\n\023MaxNotGainMessageID\030\001 \001(\003\022\020\n\010FriendID"
  "\030\002 \001(\003\"U\n\027GetSingleChatHistoryRes\022\020\n\010Fri"
  "endID\030\001 \001(\003\022(\n\004Data\030\002 \003(\0132\032.im_home_prot"
  "o.ChatMessage\")\n\025ReadOfflineMessageReq\022\020"
  "\n\010FriendID\030\001 \001(\003\"S\n\025ReadOfflineMessageRe"
  "s\022\020\n\010FriendID\030\001 \001(\003\022(\n\004Data\030\002 \003(\0132\032.im_h"
  "ome_proto.ChatMessageBDZBgithub.com/mimi"
  "s-s/IM-Service/src/common/commonproto/im"
  "_home_protob\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_home_5fmessage_2eproto_deps[1] = {
  &::descriptor_table_home_5fchat_2eproto,
};
static ::_pbi::once_flag descriptor_table_home_5fmessage_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_home_5fmessage_2eproto = {
    false, false, 419, descriptor_table_protodef_home_5fmessage_2eproto,
    "home_message.proto",
    &descriptor_table_home_5fmessage_2eproto_once, descriptor_table_home_5fmessage_2eproto_deps, 1, 4,
    schemas, file_default_instances, TableStruct_home_5fmessage_2eproto::offsets,
    file_level_metadata_home_5fmessage_2eproto, file_level_enum_descriptors_home_5fmessage_2eproto,
    file_level_service_descriptors_home_5fmessage_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_home_5fmessage_2eproto_getter() {
  return &descriptor_table_home_5fmessage_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_home_5fmessage_2eproto(&descriptor_table_home_5fmessage_2eproto);
namespace im_home_proto {

// ===================================================================

class GetSingleChatHistoryReq::_Internal {
 public:
};

GetSingleChatHistoryReq::GetSingleChatHistoryReq(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:im_home_proto.GetSingleChatHistoryReq)
}
GetSingleChatHistoryReq::GetSingleChatHistoryReq(const GetSingleChatHistoryReq& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&maxnotgainmessageid_, &from.maxnotgainmessageid_,
    static_cast<size_t>(reinterpret_cast<char*>(&friendid_) -
    reinterpret_cast<char*>(&maxnotgainmessageid_)) + sizeof(friendid_));
  // @@protoc_insertion_point(copy_constructor:im_home_proto.GetSingleChatHistoryReq)
}

inline void GetSingleChatHistoryReq::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&maxnotgainmessageid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&friendid_) -
    reinterpret_cast<char*>(&maxnotgainmessageid_)) + sizeof(friendid_));
}

GetSingleChatHistoryReq::~GetSingleChatHistoryReq() {
  // @@protoc_insertion_point(destructor:im_home_proto.GetSingleChatHistoryReq)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void GetSingleChatHistoryReq::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void GetSingleChatHistoryReq::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void GetSingleChatHistoryReq::Clear() {
// @@protoc_insertion_point(message_clear_start:im_home_proto.GetSingleChatHistoryReq)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&maxnotgainmessageid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&friendid_) -
      reinterpret_cast<char*>(&maxnotgainmessageid_)) + sizeof(friendid_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GetSingleChatHistoryReq::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int64 MaxNotGainMessageID = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          maxnotgainmessageid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int64 FriendID = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          friendid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

uint8_t* GetSingleChatHistoryReq::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:im_home_proto.GetSingleChatHistoryReq)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 MaxNotGainMessageID = 1;
  if (this->_internal_maxnotgainmessageid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(1, this->_internal_maxnotgainmessageid(), target);
  }

  // int64 FriendID = 2;
  if (this->_internal_friendid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(2, this->_internal_friendid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:im_home_proto.GetSingleChatHistoryReq)
  return target;
}

size_t GetSingleChatHistoryReq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:im_home_proto.GetSingleChatHistoryReq)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int64 MaxNotGainMessageID = 1;
  if (this->_internal_maxnotgainmessageid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_maxnotgainmessageid());
  }

  // int64 FriendID = 2;
  if (this->_internal_friendid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_friendid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData GetSingleChatHistoryReq::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    GetSingleChatHistoryReq::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetSingleChatHistoryReq::GetClassData() const { return &_class_data_; }

void GetSingleChatHistoryReq::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<GetSingleChatHistoryReq *>(to)->MergeFrom(
      static_cast<const GetSingleChatHistoryReq &>(from));
}


void GetSingleChatHistoryReq::MergeFrom(const GetSingleChatHistoryReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:im_home_proto.GetSingleChatHistoryReq)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_maxnotgainmessageid() != 0) {
    _internal_set_maxnotgainmessageid(from._internal_maxnotgainmessageid());
  }
  if (from._internal_friendid() != 0) {
    _internal_set_friendid(from._internal_friendid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void GetSingleChatHistoryReq::CopyFrom(const GetSingleChatHistoryReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:im_home_proto.GetSingleChatHistoryReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetSingleChatHistoryReq::IsInitialized() const {
  return true;
}

void GetSingleChatHistoryReq::InternalSwap(GetSingleChatHistoryReq* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(GetSingleChatHistoryReq, friendid_)
      + sizeof(GetSingleChatHistoryReq::friendid_)
      - PROTOBUF_FIELD_OFFSET(GetSingleChatHistoryReq, maxnotgainmessageid_)>(
          reinterpret_cast<char*>(&maxnotgainmessageid_),
          reinterpret_cast<char*>(&other->maxnotgainmessageid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata GetSingleChatHistoryReq::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_home_5fmessage_2eproto_getter, &descriptor_table_home_5fmessage_2eproto_once,
      file_level_metadata_home_5fmessage_2eproto[0]);
}

// ===================================================================

class GetSingleChatHistoryRes::_Internal {
 public:
};

void GetSingleChatHistoryRes::clear_data() {
  data_.Clear();
}
GetSingleChatHistoryRes::GetSingleChatHistoryRes(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  data_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:im_home_proto.GetSingleChatHistoryRes)
}
GetSingleChatHistoryRes::GetSingleChatHistoryRes(const GetSingleChatHistoryRes& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      data_(from.data_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  friendid_ = from.friendid_;
  // @@protoc_insertion_point(copy_constructor:im_home_proto.GetSingleChatHistoryRes)
}

inline void GetSingleChatHistoryRes::SharedCtor() {
friendid_ = int64_t{0};
}

GetSingleChatHistoryRes::~GetSingleChatHistoryRes() {
  // @@protoc_insertion_point(destructor:im_home_proto.GetSingleChatHistoryRes)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void GetSingleChatHistoryRes::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void GetSingleChatHistoryRes::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void GetSingleChatHistoryRes::Clear() {
// @@protoc_insertion_point(message_clear_start:im_home_proto.GetSingleChatHistoryRes)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.Clear();
  friendid_ = int64_t{0};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GetSingleChatHistoryRes::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int64 FriendID = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          friendid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .im_home_proto.ChatMessage Data = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_data(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
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

uint8_t* GetSingleChatHistoryRes::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:im_home_proto.GetSingleChatHistoryRes)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 FriendID = 1;
  if (this->_internal_friendid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(1, this->_internal_friendid(), target);
  }

  // repeated .im_home_proto.ChatMessage Data = 2;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_data_size()); i < n; i++) {
    const auto& repfield = this->_internal_data(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(2, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:im_home_proto.GetSingleChatHistoryRes)
  return target;
}

size_t GetSingleChatHistoryRes::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:im_home_proto.GetSingleChatHistoryRes)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .im_home_proto.ChatMessage Data = 2;
  total_size += 1UL * this->_internal_data_size();
  for (const auto& msg : this->data_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // int64 FriendID = 1;
  if (this->_internal_friendid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_friendid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData GetSingleChatHistoryRes::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    GetSingleChatHistoryRes::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetSingleChatHistoryRes::GetClassData() const { return &_class_data_; }

void GetSingleChatHistoryRes::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<GetSingleChatHistoryRes *>(to)->MergeFrom(
      static_cast<const GetSingleChatHistoryRes &>(from));
}


void GetSingleChatHistoryRes::MergeFrom(const GetSingleChatHistoryRes& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:im_home_proto.GetSingleChatHistoryRes)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  data_.MergeFrom(from.data_);
  if (from._internal_friendid() != 0) {
    _internal_set_friendid(from._internal_friendid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void GetSingleChatHistoryRes::CopyFrom(const GetSingleChatHistoryRes& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:im_home_proto.GetSingleChatHistoryRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetSingleChatHistoryRes::IsInitialized() const {
  return true;
}

void GetSingleChatHistoryRes::InternalSwap(GetSingleChatHistoryRes* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  data_.InternalSwap(&other->data_);
  swap(friendid_, other->friendid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GetSingleChatHistoryRes::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_home_5fmessage_2eproto_getter, &descriptor_table_home_5fmessage_2eproto_once,
      file_level_metadata_home_5fmessage_2eproto[1]);
}

// ===================================================================

class ReadOfflineMessageReq::_Internal {
 public:
};

ReadOfflineMessageReq::ReadOfflineMessageReq(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:im_home_proto.ReadOfflineMessageReq)
}
ReadOfflineMessageReq::ReadOfflineMessageReq(const ReadOfflineMessageReq& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  friendid_ = from.friendid_;
  // @@protoc_insertion_point(copy_constructor:im_home_proto.ReadOfflineMessageReq)
}

inline void ReadOfflineMessageReq::SharedCtor() {
friendid_ = int64_t{0};
}

ReadOfflineMessageReq::~ReadOfflineMessageReq() {
  // @@protoc_insertion_point(destructor:im_home_proto.ReadOfflineMessageReq)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ReadOfflineMessageReq::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void ReadOfflineMessageReq::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ReadOfflineMessageReq::Clear() {
// @@protoc_insertion_point(message_clear_start:im_home_proto.ReadOfflineMessageReq)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  friendid_ = int64_t{0};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ReadOfflineMessageReq::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int64 FriendID = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          friendid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

uint8_t* ReadOfflineMessageReq::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:im_home_proto.ReadOfflineMessageReq)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 FriendID = 1;
  if (this->_internal_friendid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(1, this->_internal_friendid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:im_home_proto.ReadOfflineMessageReq)
  return target;
}

size_t ReadOfflineMessageReq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:im_home_proto.ReadOfflineMessageReq)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int64 FriendID = 1;
  if (this->_internal_friendid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_friendid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ReadOfflineMessageReq::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ReadOfflineMessageReq::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ReadOfflineMessageReq::GetClassData() const { return &_class_data_; }

void ReadOfflineMessageReq::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ReadOfflineMessageReq *>(to)->MergeFrom(
      static_cast<const ReadOfflineMessageReq &>(from));
}


void ReadOfflineMessageReq::MergeFrom(const ReadOfflineMessageReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:im_home_proto.ReadOfflineMessageReq)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_friendid() != 0) {
    _internal_set_friendid(from._internal_friendid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ReadOfflineMessageReq::CopyFrom(const ReadOfflineMessageReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:im_home_proto.ReadOfflineMessageReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ReadOfflineMessageReq::IsInitialized() const {
  return true;
}

void ReadOfflineMessageReq::InternalSwap(ReadOfflineMessageReq* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(friendid_, other->friendid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ReadOfflineMessageReq::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_home_5fmessage_2eproto_getter, &descriptor_table_home_5fmessage_2eproto_once,
      file_level_metadata_home_5fmessage_2eproto[2]);
}

// ===================================================================

class ReadOfflineMessageRes::_Internal {
 public:
};

void ReadOfflineMessageRes::clear_data() {
  data_.Clear();
}
ReadOfflineMessageRes::ReadOfflineMessageRes(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  data_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:im_home_proto.ReadOfflineMessageRes)
}
ReadOfflineMessageRes::ReadOfflineMessageRes(const ReadOfflineMessageRes& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      data_(from.data_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  friendid_ = from.friendid_;
  // @@protoc_insertion_point(copy_constructor:im_home_proto.ReadOfflineMessageRes)
}

inline void ReadOfflineMessageRes::SharedCtor() {
friendid_ = int64_t{0};
}

ReadOfflineMessageRes::~ReadOfflineMessageRes() {
  // @@protoc_insertion_point(destructor:im_home_proto.ReadOfflineMessageRes)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ReadOfflineMessageRes::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void ReadOfflineMessageRes::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ReadOfflineMessageRes::Clear() {
// @@protoc_insertion_point(message_clear_start:im_home_proto.ReadOfflineMessageRes)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.Clear();
  friendid_ = int64_t{0};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ReadOfflineMessageRes::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int64 FriendID = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          friendid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .im_home_proto.ChatMessage Data = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_data(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
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

uint8_t* ReadOfflineMessageRes::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:im_home_proto.ReadOfflineMessageRes)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 FriendID = 1;
  if (this->_internal_friendid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(1, this->_internal_friendid(), target);
  }

  // repeated .im_home_proto.ChatMessage Data = 2;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_data_size()); i < n; i++) {
    const auto& repfield = this->_internal_data(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(2, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:im_home_proto.ReadOfflineMessageRes)
  return target;
}

size_t ReadOfflineMessageRes::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:im_home_proto.ReadOfflineMessageRes)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .im_home_proto.ChatMessage Data = 2;
  total_size += 1UL * this->_internal_data_size();
  for (const auto& msg : this->data_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // int64 FriendID = 1;
  if (this->_internal_friendid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_friendid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ReadOfflineMessageRes::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ReadOfflineMessageRes::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ReadOfflineMessageRes::GetClassData() const { return &_class_data_; }

void ReadOfflineMessageRes::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ReadOfflineMessageRes *>(to)->MergeFrom(
      static_cast<const ReadOfflineMessageRes &>(from));
}


void ReadOfflineMessageRes::MergeFrom(const ReadOfflineMessageRes& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:im_home_proto.ReadOfflineMessageRes)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  data_.MergeFrom(from.data_);
  if (from._internal_friendid() != 0) {
    _internal_set_friendid(from._internal_friendid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ReadOfflineMessageRes::CopyFrom(const ReadOfflineMessageRes& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:im_home_proto.ReadOfflineMessageRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ReadOfflineMessageRes::IsInitialized() const {
  return true;
}

void ReadOfflineMessageRes::InternalSwap(ReadOfflineMessageRes* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  data_.InternalSwap(&other->data_);
  swap(friendid_, other->friendid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ReadOfflineMessageRes::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_home_5fmessage_2eproto_getter, &descriptor_table_home_5fmessage_2eproto_once,
      file_level_metadata_home_5fmessage_2eproto[3]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace im_home_proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::im_home_proto::GetSingleChatHistoryReq*
Arena::CreateMaybeMessage< ::im_home_proto::GetSingleChatHistoryReq >(Arena* arena) {
  return Arena::CreateMessageInternal< ::im_home_proto::GetSingleChatHistoryReq >(arena);
}
template<> PROTOBUF_NOINLINE ::im_home_proto::GetSingleChatHistoryRes*
Arena::CreateMaybeMessage< ::im_home_proto::GetSingleChatHistoryRes >(Arena* arena) {
  return Arena::CreateMessageInternal< ::im_home_proto::GetSingleChatHistoryRes >(arena);
}
template<> PROTOBUF_NOINLINE ::im_home_proto::ReadOfflineMessageReq*
Arena::CreateMaybeMessage< ::im_home_proto::ReadOfflineMessageReq >(Arena* arena) {
  return Arena::CreateMessageInternal< ::im_home_proto::ReadOfflineMessageReq >(arena);
}
template<> PROTOBUF_NOINLINE ::im_home_proto::ReadOfflineMessageRes*
Arena::CreateMaybeMessage< ::im_home_proto::ReadOfflineMessageRes >(Arena* arena) {
  return Arena::CreateMessageInternal< ::im_home_proto::ReadOfflineMessageRes >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>