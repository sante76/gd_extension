/**************************************************************************/
/*  retarget_modifier3d.hpp                                               */
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

#ifndef GODOT_CPP_RETARGET_MODIFIER3D_HPP
#define GODOT_CPP_RETARGET_MODIFIER3D_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/skeleton_modifier3d.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class SkeletonProfile;

class RetargetModifier3D : public SkeletonModifier3D {
	GDEXTENSION_CLASS(RetargetModifier3D, SkeletonModifier3D)

public:
	enum TransformFlag : uint64_t {
		TRANSFORM_FLAG_POSITION = 1,
		TRANSFORM_FLAG_ROTATION = 2,
		TRANSFORM_FLAG_SCALE = 4,
		TRANSFORM_FLAG_ALL = 7,
	};

	void set_profile(const Ref<SkeletonProfile> &p_profile);
	Ref<SkeletonProfile> get_profile() const;
	void set_use_global_pose(bool p_use_global_pose);
	bool is_using_global_pose() const;
	void set_enable_flags(BitField<RetargetModifier3D::TransformFlag> p_enable_flags);
	BitField<RetargetModifier3D::TransformFlag> get_enable_flags() const;
	void set_position_enabled(bool p_enabled);
	bool is_position_enabled() const;
	void set_rotation_enabled(bool p_enabled);
	bool is_rotation_enabled() const;
	void set_scale_enabled(bool p_enabled);
	bool is_scale_enabled() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		SkeletonModifier3D::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_BITFIELD_CAST(RetargetModifier3D::TransformFlag);

#endif // ! GODOT_CPP_RETARGET_MODIFIER3D_HPP
