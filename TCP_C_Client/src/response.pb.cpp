// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: response.proto

#include "response.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace command {
namespace response {
        template <typename>
PROTOBUF_CONSTEXPR ResponseMessage::ResponseMessage(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_.message_)*/ {
          &::_pbi::fixed_address_empty_string,
          ::_pbi::ConstantInitialized{},
      },
      /*decltype(_impl_.is_successful_)*/ false,
      /*decltype(_impl_._cached_size_)*/ {},
    } {}
struct ResponseMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ResponseMessageDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ResponseMessageDefaultTypeInternal() {}
  union {
    ResponseMessage _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ResponseMessageDefaultTypeInternal _ResponseMessage_default_instance_;
}  // namespace response
}  // namespace command
static ::_pb::Metadata file_level_metadata_response_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_response_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_response_2eproto = nullptr;
const ::uint32_t TableStruct_response_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::command::response::ResponseMessage, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::command::response::ResponseMessage, _impl_.is_successful_),
    PROTOBUF_FIELD_OFFSET(::command::response::ResponseMessage, _impl_.message_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::command::response::ResponseMessage)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::command::response::_ResponseMessage_default_instance_._instance,
};
const char descriptor_table_protodef_response_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\016response.proto\022\020command.response\"9\n\017Re"
    "sponseMessage\022\025\n\ris_successful\030\001 \001(\010\022\017\n\007"
    "message\030\002 \001(\tb\006proto3"
};
static ::absl::once_flag descriptor_table_response_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_response_2eproto = {
    false,
    false,
    101,
    descriptor_table_protodef_response_2eproto,
    "response.proto",
    &descriptor_table_response_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_response_2eproto::offsets,
    file_level_metadata_response_2eproto,
    file_level_enum_descriptors_response_2eproto,
    file_level_service_descriptors_response_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_response_2eproto_getter() {
  return &descriptor_table_response_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_response_2eproto(&descriptor_table_response_2eproto);
namespace command {
namespace response {
// ===================================================================

class ResponseMessage::_Internal {
 public:
};

ResponseMessage::ResponseMessage(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:command.response.ResponseMessage)
}
ResponseMessage::ResponseMessage(const ResponseMessage& from) : ::google::protobuf::Message() {
  ResponseMessage* const _this = this;
  (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.message_){},
      decltype(_impl_.is_successful_){},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  _impl_.message_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.message_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_message().empty()) {
    _this->_impl_.message_.Set(from._internal_message(), _this->GetArenaForAllocation());
  }
  _this->_impl_.is_successful_ = from._impl_.is_successful_;

  // @@protoc_insertion_point(copy_constructor:command.response.ResponseMessage)
}
inline void ResponseMessage::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.message_){},
      decltype(_impl_.is_successful_){false},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _impl_.message_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.message_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}
ResponseMessage::~ResponseMessage() {
  // @@protoc_insertion_point(destructor:command.response.ResponseMessage)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void ResponseMessage::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.message_.Destroy();
}
void ResponseMessage::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void ResponseMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:command.response.ResponseMessage)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.message_.ClearToEmpty();
  _impl_.is_successful_ = false;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* ResponseMessage::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 48, 2> ResponseMessage::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_ResponseMessage_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // string message = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(ResponseMessage, _impl_.message_)}},
    // bool is_successful = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(ResponseMessage, _impl_.is_successful_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(ResponseMessage, _impl_.is_successful_)}},
  }}, {{
    65535, 65535
  }}, {{
    // bool is_successful = 1;
    {PROTOBUF_FIELD_OFFSET(ResponseMessage, _impl_.is_successful_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
    // string message = 2;
    {PROTOBUF_FIELD_OFFSET(ResponseMessage, _impl_.message_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\40\0\7\0\0\0\0\0"
    "command.response.ResponseMessage"
    "message"
  }},
};

::uint8_t* ResponseMessage::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:command.response.ResponseMessage)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // bool is_successful = 1;
  if (this->_internal_is_successful() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        1, this->_internal_is_successful(), target);
  }

  // string message = 2;
  if (!this->_internal_message().empty()) {
    const std::string& _s = this->_internal_message();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "command.response.ResponseMessage.message");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:command.response.ResponseMessage)
  return target;
}

::size_t ResponseMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:command.response.ResponseMessage)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string message = 2;
  if (!this->_internal_message().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_message());
  }

  // bool is_successful = 1;
  if (this->_internal_is_successful() != 0) {
    total_size += 2;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData ResponseMessage::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    ResponseMessage::MergeImpl
};
const ::google::protobuf::Message::ClassData*ResponseMessage::GetClassData() const { return &_class_data_; }


void ResponseMessage::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<ResponseMessage*>(&to_msg);
  auto& from = static_cast<const ResponseMessage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:command.response.ResponseMessage)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_message().empty()) {
    _this->_internal_set_message(from._internal_message());
  }
  if (from._internal_is_successful() != 0) {
    _this->_internal_set_is_successful(from._internal_is_successful());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void ResponseMessage::CopyFrom(const ResponseMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:command.response.ResponseMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool ResponseMessage::IsInitialized() const {
  return true;
}

void ResponseMessage::InternalSwap(ResponseMessage* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.message_, lhs_arena,
                                       &other->_impl_.message_, rhs_arena);
        swap(_impl_.is_successful_, other->_impl_.is_successful_);
}

::google::protobuf::Metadata ResponseMessage::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_response_2eproto_getter, &descriptor_table_response_2eproto_once,
      file_level_metadata_response_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace response
}  // namespace command
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"