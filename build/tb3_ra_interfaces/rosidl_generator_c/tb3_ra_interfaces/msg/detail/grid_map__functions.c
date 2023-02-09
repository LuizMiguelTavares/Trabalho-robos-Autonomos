// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tb3_ra_interfaces:msg/GridMap.idl
// generated code does not contain a copyright notice
#include "tb3_ra_interfaces/msg/detail/grid_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `x_grid`
// Member `y_grid`
// Member `weight`
// Member `degree`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
tb3_ra_interfaces__msg__GridMap__init(tb3_ra_interfaces__msg__GridMap * msg)
{
  if (!msg) {
    return false;
  }
  // width
  // heigth
  // resolution
  // x_grid
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->x_grid, 0)) {
    tb3_ra_interfaces__msg__GridMap__fini(msg);
    return false;
  }
  // y_grid
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->y_grid, 0)) {
    tb3_ra_interfaces__msg__GridMap__fini(msg);
    return false;
  }
  // weight
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->weight, 0)) {
    tb3_ra_interfaces__msg__GridMap__fini(msg);
    return false;
  }
  // degree
  if (!rosidl_runtime_c__float__Sequence__init(&msg->degree, 0)) {
    tb3_ra_interfaces__msg__GridMap__fini(msg);
    return false;
  }
  // x_to_go
  // y_to_go
  return true;
}

void
tb3_ra_interfaces__msg__GridMap__fini(tb3_ra_interfaces__msg__GridMap * msg)
{
  if (!msg) {
    return;
  }
  // width
  // heigth
  // resolution
  // x_grid
  rosidl_runtime_c__int32__Sequence__fini(&msg->x_grid);
  // y_grid
  rosidl_runtime_c__int32__Sequence__fini(&msg->y_grid);
  // weight
  rosidl_runtime_c__int32__Sequence__fini(&msg->weight);
  // degree
  rosidl_runtime_c__float__Sequence__fini(&msg->degree);
  // x_to_go
  // y_to_go
}

bool
tb3_ra_interfaces__msg__GridMap__are_equal(const tb3_ra_interfaces__msg__GridMap * lhs, const tb3_ra_interfaces__msg__GridMap * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // heigth
  if (lhs->heigth != rhs->heigth) {
    return false;
  }
  // resolution
  if (lhs->resolution != rhs->resolution) {
    return false;
  }
  // x_grid
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->x_grid), &(rhs->x_grid)))
  {
    return false;
  }
  // y_grid
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->y_grid), &(rhs->y_grid)))
  {
    return false;
  }
  // weight
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->weight), &(rhs->weight)))
  {
    return false;
  }
  // degree
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->degree), &(rhs->degree)))
  {
    return false;
  }
  // x_to_go
  if (lhs->x_to_go != rhs->x_to_go) {
    return false;
  }
  // y_to_go
  if (lhs->y_to_go != rhs->y_to_go) {
    return false;
  }
  return true;
}

bool
tb3_ra_interfaces__msg__GridMap__copy(
  const tb3_ra_interfaces__msg__GridMap * input,
  tb3_ra_interfaces__msg__GridMap * output)
{
  if (!input || !output) {
    return false;
  }
  // width
  output->width = input->width;
  // heigth
  output->heigth = input->heigth;
  // resolution
  output->resolution = input->resolution;
  // x_grid
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->x_grid), &(output->x_grid)))
  {
    return false;
  }
  // y_grid
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->y_grid), &(output->y_grid)))
  {
    return false;
  }
  // weight
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->weight), &(output->weight)))
  {
    return false;
  }
  // degree
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->degree), &(output->degree)))
  {
    return false;
  }
  // x_to_go
  output->x_to_go = input->x_to_go;
  // y_to_go
  output->y_to_go = input->y_to_go;
  return true;
}

tb3_ra_interfaces__msg__GridMap *
tb3_ra_interfaces__msg__GridMap__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_ra_interfaces__msg__GridMap * msg = (tb3_ra_interfaces__msg__GridMap *)allocator.allocate(sizeof(tb3_ra_interfaces__msg__GridMap), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tb3_ra_interfaces__msg__GridMap));
  bool success = tb3_ra_interfaces__msg__GridMap__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tb3_ra_interfaces__msg__GridMap__destroy(tb3_ra_interfaces__msg__GridMap * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tb3_ra_interfaces__msg__GridMap__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tb3_ra_interfaces__msg__GridMap__Sequence__init(tb3_ra_interfaces__msg__GridMap__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_ra_interfaces__msg__GridMap * data = NULL;

  if (size) {
    data = (tb3_ra_interfaces__msg__GridMap *)allocator.zero_allocate(size, sizeof(tb3_ra_interfaces__msg__GridMap), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tb3_ra_interfaces__msg__GridMap__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tb3_ra_interfaces__msg__GridMap__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tb3_ra_interfaces__msg__GridMap__Sequence__fini(tb3_ra_interfaces__msg__GridMap__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tb3_ra_interfaces__msg__GridMap__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tb3_ra_interfaces__msg__GridMap__Sequence *
tb3_ra_interfaces__msg__GridMap__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_ra_interfaces__msg__GridMap__Sequence * array = (tb3_ra_interfaces__msg__GridMap__Sequence *)allocator.allocate(sizeof(tb3_ra_interfaces__msg__GridMap__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tb3_ra_interfaces__msg__GridMap__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tb3_ra_interfaces__msg__GridMap__Sequence__destroy(tb3_ra_interfaces__msg__GridMap__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tb3_ra_interfaces__msg__GridMap__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tb3_ra_interfaces__msg__GridMap__Sequence__are_equal(const tb3_ra_interfaces__msg__GridMap__Sequence * lhs, const tb3_ra_interfaces__msg__GridMap__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tb3_ra_interfaces__msg__GridMap__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tb3_ra_interfaces__msg__GridMap__Sequence__copy(
  const tb3_ra_interfaces__msg__GridMap__Sequence * input,
  tb3_ra_interfaces__msg__GridMap__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tb3_ra_interfaces__msg__GridMap);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tb3_ra_interfaces__msg__GridMap * data =
      (tb3_ra_interfaces__msg__GridMap *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tb3_ra_interfaces__msg__GridMap__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tb3_ra_interfaces__msg__GridMap__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tb3_ra_interfaces__msg__GridMap__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
