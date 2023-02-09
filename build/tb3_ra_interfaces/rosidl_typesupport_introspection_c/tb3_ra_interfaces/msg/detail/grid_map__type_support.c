// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tb3_ra_interfaces:msg/GridMap.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tb3_ra_interfaces/msg/detail/grid_map__rosidl_typesupport_introspection_c.h"
#include "tb3_ra_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tb3_ra_interfaces/msg/detail/grid_map__functions.h"
#include "tb3_ra_interfaces/msg/detail/grid_map__struct.h"


// Include directives for member types
// Member `x_grid`
// Member `y_grid`
// Member `weight`
// Member `degree`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tb3_ra_interfaces__msg__GridMap__init(message_memory);
}

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_fini_function(void * message_memory)
{
  tb3_ra_interfaces__msg__GridMap__fini(message_memory);
}

size_t tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__x_grid(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__x_grid(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__x_grid(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__x_grid(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__x_grid(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__x_grid(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__x_grid(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__x_grid(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__y_grid(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__y_grid(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__y_grid(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__y_grid(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__y_grid(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__y_grid(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__y_grid(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__y_grid(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__weight(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__weight(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__weight(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__weight(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__weight(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__weight(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__weight(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__weight(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__degree(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__degree(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__degree(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__degree(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__degree(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__degree(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__degree(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__degree(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_member_array[9] = {
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_ra_interfaces__msg__GridMap, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heigth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_ra_interfaces__msg__GridMap, heigth),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "resolution",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_ra_interfaces__msg__GridMap, resolution),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x_grid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_ra_interfaces__msg__GridMap, x_grid),  // bytes offset in struct
    NULL,  // default value
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__x_grid,  // size() function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__x_grid,  // get_const(index) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__x_grid,  // get(index) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__x_grid,  // fetch(index, &value) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__x_grid,  // assign(index, value) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__x_grid  // resize(index) function pointer
  },
  {
    "y_grid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_ra_interfaces__msg__GridMap, y_grid),  // bytes offset in struct
    NULL,  // default value
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__y_grid,  // size() function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__y_grid,  // get_const(index) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__y_grid,  // get(index) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__y_grid,  // fetch(index, &value) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__y_grid,  // assign(index, value) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__y_grid  // resize(index) function pointer
  },
  {
    "weight",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_ra_interfaces__msg__GridMap, weight),  // bytes offset in struct
    NULL,  // default value
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__weight,  // size() function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__weight,  // get_const(index) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__weight,  // get(index) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__weight,  // fetch(index, &value) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__weight,  // assign(index, value) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__weight  // resize(index) function pointer
  },
  {
    "degree",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_ra_interfaces__msg__GridMap, degree),  // bytes offset in struct
    NULL,  // default value
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__degree,  // size() function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__degree,  // get_const(index) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__degree,  // get(index) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__degree,  // fetch(index, &value) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__degree,  // assign(index, value) function pointer
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__degree  // resize(index) function pointer
  },
  {
    "x_to_go",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_ra_interfaces__msg__GridMap, x_to_go),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y_to_go",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_ra_interfaces__msg__GridMap, y_to_go),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_members = {
  "tb3_ra_interfaces__msg",  // message namespace
  "GridMap",  // message name
  9,  // number of fields
  sizeof(tb3_ra_interfaces__msg__GridMap),
  tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_member_array,  // message members
  tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_init_function,  // function to initialize message memory (memory has to be allocated)
  tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_type_support_handle = {
  0,
  &tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tb3_ra_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tb3_ra_interfaces, msg, GridMap)() {
  if (!tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_type_support_handle.typesupport_identifier) {
    tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tb3_ra_interfaces__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
