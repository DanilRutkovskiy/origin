#pragma once
#include <iostream>
#include <exception>

class bad_triangle : public std::exception {
public:
	virtual const char* what() const noexcept override;
};

class bad_triangle_angle_sum : public bad_triangle {
public:
	virtual const char* what() const noexcept override;
};

class bad_triangle_side_count: public bad_triangle {
public:
	virtual const char* what() const noexcept override;
};

class bad_right_triangle : public bad_triangle {
public:
	virtual const char* what() const noexcept override;
};

class bad_equilateral_triangle : public bad_triangle {
public:
	virtual const char* what() const noexcept override;
};

class bad_tetragon : public std::exception {
public:
	virtual const char* what() const noexcept override;
};

class bad_tetragon_angle_sum : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};

class bad_tetragon_side_count : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};

class bad_rectangle_side_equality : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};

class bad_rectangle_angle : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};

class bad_square_side : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};

class bad_square_angle : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};

class bad_parallelogram_angle : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};

class bad_parallelogram_side : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};

class bad_rhombus_side : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};

class bad_rhombus_angle : public bad_tetragon {
public:
	virtual const char* what() const noexcept override;
};