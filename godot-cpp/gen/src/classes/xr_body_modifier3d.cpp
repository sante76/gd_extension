/**************************************************************************/
/*  xr_body_modifier3d.cpp                                                */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

// THIS FILE IS GENERATED. EDITS WILL BE LOST.

#include <godot_cpp/classes/xr_body_modifier3d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

void XRBodyModifier3D::set_body_tracker(const StringName &p_tracker_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyModifier3D::get_class_static()._native_ptr(), StringName("set_body_tracker")._native_ptr(), 3304788590);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_tracker_name);
}

StringName XRBodyModifier3D::get_body_tracker() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyModifier3D::get_class_static()._native_ptr(), StringName("get_body_tracker")._native_ptr(), 2002593661);
	CHECK_METHOD_BIND_RET(_gde_method_bind, StringName());
	return internal::_call_native_mb_ret<StringName>(_gde_method_bind, _owner);
}

void XRBodyModifier3D::set_body_update(BitField<XRBodyModifier3D::BodyUpdate> p_body_update) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyModifier3D::get_class_static()._native_ptr(), StringName("set_body_update")._native_ptr(), 2211199417);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_body_update);
}

BitField<XRBodyModifier3D::BodyUpdate> XRBodyModifier3D::get_body_update() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyModifier3D::get_class_static()._native_ptr(), StringName("get_body_update")._native_ptr(), 2642335328);
	CHECK_METHOD_BIND_RET(_gde_method_bind, BitField<XRBodyModifier3D::BodyUpdate>(0));
	return (int64_t)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void XRBodyModifier3D::set_bone_update(XRBodyModifier3D::BoneUpdate p_bone_update) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyModifier3D::get_class_static()._native_ptr(), StringName("set_bone_update")._native_ptr(), 3356796943);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_bone_update_encoded;
	PtrToArg<int64_t>::encode(p_bone_update, &p_bone_update_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_bone_update_encoded);
}

XRBodyModifier3D::BoneUpdate XRBodyModifier3D::get_bone_update() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyModifier3D::get_class_static()._native_ptr(), StringName("get_bone_update")._native_ptr(), 1309305964);
	CHECK_METHOD_BIND_RET(_gde_method_bind, XRBodyModifier3D::BoneUpdate(0));
	return (XRBodyModifier3D::BoneUpdate)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

} // namespace godot
