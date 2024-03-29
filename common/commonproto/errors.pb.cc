// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: errors.proto

#include "errors.pb.h"

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

namespace im_error_proto {
PROTOBUF_CONSTEXPR CommonError::CommonError(
    ::_pbi::ConstantInitialized)
  : reqpayload_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , respayload_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , code_(0)

  , reqmsgid_(0u)
  , resmsgid_(0u){}
struct CommonErrorDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CommonErrorDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~CommonErrorDefaultTypeInternal() {}
  union {
    CommonError _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CommonErrorDefaultTypeInternal _CommonError_default_instance_;
}  // namespace im_error_proto
static ::_pb::Metadata file_level_metadata_errors_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_errors_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_errors_2eproto = nullptr;

const uint32_t TableStruct_errors_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::im_error_proto::CommonError, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::im_error_proto::CommonError, code_),
  PROTOBUF_FIELD_OFFSET(::im_error_proto::CommonError, reqmsgid_),
  PROTOBUF_FIELD_OFFSET(::im_error_proto::CommonError, resmsgid_),
  PROTOBUF_FIELD_OFFSET(::im_error_proto::CommonError, reqpayload_),
  PROTOBUF_FIELD_OFFSET(::im_error_proto::CommonError, respayload_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::im_error_proto::CommonError)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::im_error_proto::_CommonError_default_instance_._instance,
};

const char descriptor_table_protodef_errors_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014errors.proto\022\016im_error_proto\"\200\001\n\013Commo"
  "nError\022%\n\004Code\030\001 \001(\0162\027.im_error_proto.Er"
  "rCode\022\020\n\010ReqMsgID\030\002 \001(\r\022\020\n\010ResMsgID\030\003 \001("
  "\r\022\022\n\nReqPayload\030\004 \001(\t\022\022\n\nResPayload\030\005 \001("
  "\t*\201\002\n\007ErrCode\022\013\n\007success\020\000\022\031\n\025common_une"
  "xpected_err\020\001\022\017\n\013db_read_err\020\002\022\020\n\014db_wri"
  "te_err\020\003\022\035\n\030account_user_name_repeat\020\351\007\022"
  "\036\n\031account_account_not_found\020\352\007\022\037\n\032accou"
  "nt_password_incorrect\020\353\007\022#\n\036friends_user"
  "_already_be_friend\020\321\017\022&\n!friends_user_al"
  "ready_apply_friend\020\322\017BEZCgithub.com/mimi"
  "s-s/IM-Service/src/common/commonproto/im"
  "_error_protob\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_errors_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_errors_2eproto = {
    false, false, 500, descriptor_table_protodef_errors_2eproto,
    "errors.proto",
    &descriptor_table_errors_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_errors_2eproto::offsets,
    file_level_metadata_errors_2eproto, file_level_enum_descriptors_errors_2eproto,
    file_level_service_descriptors_errors_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_errors_2eproto_getter() {
  return &descriptor_table_errors_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_errors_2eproto(&descriptor_table_errors_2eproto);
namespace im_error_proto {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ErrCode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_errors_2eproto);
  return file_level_enum_descriptors_errors_2eproto[0];
}
bool ErrCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 1001:
    case 1002:
    case 1003:
    case 2001:
    case 2002:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class CommonError::_Internal {
 public:
};

CommonError::CommonError(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:im_error_proto.CommonError)
}
CommonError::CommonError(const CommonError& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  reqpayload_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    reqpayload_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_reqpayload().empty()) {
    reqpayload_.Set(from._internal_reqpayload(), 
      GetArenaForAllocation());
  }
  respayload_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    respayload_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_respayload().empty()) {
    respayload_.Set(from._internal_respayload(), 
      GetArenaForAllocation());
  }
  ::memcpy(&code_, &from.code_,
    static_cast<size_t>(reinterpret_cast<char*>(&resmsgid_) -
    reinterpret_cast<char*>(&code_)) + sizeof(resmsgid_));
  // @@protoc_insertion_point(copy_constructor:im_error_proto.CommonError)
}

inline void CommonError::SharedCtor() {
reqpayload_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  reqpayload_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
respayload_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  respayload_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&code_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&resmsgid_) -
    reinterpret_cast<char*>(&code_)) + sizeof(resmsgid_));
}

CommonError::~CommonError() {
  // @@protoc_insertion_point(destructor:im_error_proto.CommonError)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CommonError::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  reqpayload_.Destroy();
  respayload_.Destroy();
}

void CommonError::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void CommonError::Clear() {
// @@protoc_insertion_point(message_clear_start:im_error_proto.CommonError)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  reqpayload_.ClearToEmpty();
  respayload_.ClearToEmpty();
  ::memset(&code_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&resmsgid_) -
      reinterpret_cast<char*>(&code_)) + sizeof(resmsgid_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CommonError::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .im_error_proto.ErrCode Code = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_code(static_cast<::im_error_proto::ErrCode>(val));
        } else
          goto handle_unusual;
        continue;
      // uint32 ReqMsgID = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          reqmsgid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 ResMsgID = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          resmsgid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string ReqPayload = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_reqpayload();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "im_error_proto.CommonError.ReqPayload"));
        } else
          goto handle_unusual;
        continue;
      // string ResPayload = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          auto str = _internal_mutable_respayload();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "im_error_proto.CommonError.ResPayload"));
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

uint8_t* CommonError::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:im_error_proto.CommonError)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .im_error_proto.ErrCode Code = 1;
  if (this->_internal_code() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      1, this->_internal_code(), target);
  }

  // uint32 ReqMsgID = 2;
  if (this->_internal_reqmsgid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(2, this->_internal_reqmsgid(), target);
  }

  // uint32 ResMsgID = 3;
  if (this->_internal_resmsgid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(3, this->_internal_resmsgid(), target);
  }

  // string ReqPayload = 4;
  if (!this->_internal_reqpayload().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_reqpayload().data(), static_cast<int>(this->_internal_reqpayload().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "im_error_proto.CommonError.ReqPayload");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_reqpayload(), target);
  }

  // string ResPayload = 5;
  if (!this->_internal_respayload().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_respayload().data(), static_cast<int>(this->_internal_respayload().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "im_error_proto.CommonError.ResPayload");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_respayload(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:im_error_proto.CommonError)
  return target;
}

size_t CommonError::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:im_error_proto.CommonError)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string ReqPayload = 4;
  if (!this->_internal_reqpayload().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_reqpayload());
  }

  // string ResPayload = 5;
  if (!this->_internal_respayload().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_respayload());
  }

  // .im_error_proto.ErrCode Code = 1;
  if (this->_internal_code() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_code());
  }

  // uint32 ReqMsgID = 2;
  if (this->_internal_reqmsgid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_reqmsgid());
  }

  // uint32 ResMsgID = 3;
  if (this->_internal_resmsgid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_resmsgid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CommonError::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    CommonError::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CommonError::GetClassData() const { return &_class_data_; }

void CommonError::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<CommonError *>(to)->MergeFrom(
      static_cast<const CommonError &>(from));
}


void CommonError::MergeFrom(const CommonError& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:im_error_proto.CommonError)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_reqpayload().empty()) {
    _internal_set_reqpayload(from._internal_reqpayload());
  }
  if (!from._internal_respayload().empty()) {
    _internal_set_respayload(from._internal_respayload());
  }
  if (from._internal_code() != 0) {
    _internal_set_code(from._internal_code());
  }
  if (from._internal_reqmsgid() != 0) {
    _internal_set_reqmsgid(from._internal_reqmsgid());
  }
  if (from._internal_resmsgid() != 0) {
    _internal_set_resmsgid(from._internal_resmsgid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CommonError::CopyFrom(const CommonError& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:im_error_proto.CommonError)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CommonError::IsInitialized() const {
  return true;
}

void CommonError::InternalSwap(CommonError* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &reqpayload_, lhs_arena,
      &other->reqpayload_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &respayload_, lhs_arena,
      &other->respayload_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(CommonError, resmsgid_)
      + sizeof(CommonError::resmsgid_)
      - PROTOBUF_FIELD_OFFSET(CommonError, code_)>(
          reinterpret_cast<char*>(&code_),
          reinterpret_cast<char*>(&other->code_));
}

::PROTOBUF_NAMESPACE_ID::Metadata CommonError::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_errors_2eproto_getter, &descriptor_table_errors_2eproto_once,
      file_level_metadata_errors_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace im_error_proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::im_error_proto::CommonError*
Arena::CreateMaybeMessage< ::im_error_proto::CommonError >(Arena* arena) {
  return Arena::CreateMessageInternal< ::im_error_proto::CommonError >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
