// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tb3_ra_interfaces:msg/GridMap.idl
// generated code does not contain a copyright notice
#include "tb3_ra_interfaces/msg/detail/grid_map__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tb3_ra_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tb3_ra_interfaces/msg/detail/grid_map__struct.h"
#include "tb3_ra_interfaces/msg/detail/grid_map__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // degree, weight, x_grid, y_grid
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // degree, weight, x_grid, y_grid

// forward declare type support functions


using _GridMap__ros_msg_type = tb3_ra_interfaces__msg__GridMap;

static bool _GridMap__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GridMap__ros_msg_type * ros_message = static_cast<const _GridMap__ros_msg_type *>(untyped_ros_message);
  // Field name: width
  {
    cdr << ros_message->width;
  }

  // Field name: heigth
  {
    cdr << ros_message->heigth;
  }

  // Field name: resolution
  {
    cdr << ros_message->resolution;
  }

  // Field name: x_grid
  {
    size_t size = ros_message->x_grid.size;
    auto array_ptr = ros_message->x_grid.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: y_grid
  {
    size_t size = ros_message->y_grid.size;
    auto array_ptr = ros_message->y_grid.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: weight
  {
    size_t size = ros_message->weight.size;
    auto array_ptr = ros_message->weight.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: degree
  {
    size_t size = ros_message->degree.size;
    auto array_ptr = ros_message->degree.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: x_to_go
  {
    cdr << ros_message->x_to_go;
  }

  // Field name: y_to_go
  {
    cdr << ros_message->y_to_go;
  }

  return true;
}

static bool _GridMap__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GridMap__ros_msg_type * ros_message = static_cast<_GridMap__ros_msg_type *>(untyped_ros_message);
  // Field name: width
  {
    cdr >> ros_message->width;
  }

  // Field name: heigth
  {
    cdr >> ros_message->heigth;
  }

  // Field name: resolution
  {
    cdr >> ros_message->resolution;
  }

  // Field name: x_grid
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->x_grid.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->x_grid);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->x_grid, size)) {
      fprintf(stderr, "failed to create array for field 'x_grid'");
      return false;
    }
    auto array_ptr = ros_message->x_grid.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: y_grid
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->y_grid.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->y_grid);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->y_grid, size)) {
      fprintf(stderr, "failed to create array for field 'y_grid'");
      return false;
    }
    auto array_ptr = ros_message->y_grid.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: weight
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->weight.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->weight);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->weight, size)) {
      fprintf(stderr, "failed to create array for field 'weight'");
      return false;
    }
    auto array_ptr = ros_message->weight.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: degree
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->degree.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->degree);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->degree, size)) {
      fprintf(stderr, "failed to create array for field 'degree'");
      return false;
    }
    auto array_ptr = ros_message->degree.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: x_to_go
  {
    cdr >> ros_message->x_to_go;
  }

  // Field name: y_to_go
  {
    cdr >> ros_message->y_to_go;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tb3_ra_interfaces
size_t get_serialized_size_tb3_ra_interfaces__msg__GridMap(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GridMap__ros_msg_type * ros_message = static_cast<const _GridMap__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name width
  {
    size_t item_size = sizeof(ros_message->width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name heigth
  {
    size_t item_size = sizeof(ros_message->heigth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name resolution
  {
    size_t item_size = sizeof(ros_message->resolution);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x_grid
  {
    size_t array_size = ros_message->x_grid.size;
    auto array_ptr = ros_message->x_grid.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_grid
  {
    size_t array_size = ros_message->y_grid.size;
    auto array_ptr = ros_message->y_grid.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name weight
  {
    size_t array_size = ros_message->weight.size;
    auto array_ptr = ros_message->weight.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name degree
  {
    size_t array_size = ros_message->degree.size;
    auto array_ptr = ros_message->degree.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x_to_go
  {
    size_t item_size = sizeof(ros_message->x_to_go);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_to_go
  {
    size_t item_size = sizeof(ros_message->y_to_go);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GridMap__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tb3_ra_interfaces__msg__GridMap(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tb3_ra_interfaces
size_t max_serialized_size_tb3_ra_interfaces__msg__GridMap(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: width
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: heigth
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: resolution
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: x_grid
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y_grid
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: weight
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: degree
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: x_to_go
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y_to_go
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _GridMap__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tb3_ra_interfaces__msg__GridMap(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GridMap = {
  "tb3_ra_interfaces::msg",
  "GridMap",
  _GridMap__cdr_serialize,
  _GridMap__cdr_deserialize,
  _GridMap__get_serialized_size,
  _GridMap__max_serialized_size
};

static rosidl_message_type_support_t _GridMap__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GridMap,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tb3_ra_interfaces, msg, GridMap)() {
  return &_GridMap__type_support;
}

#if defined(__cplusplus)
}
#endif
