#pragma once

#include <random>

#include "strategy.h"

class Betray : public Strategy {	// ������ ������
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::BETRAY;
};

class Cooperate : public Strategy {	// ������ ������������
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::COOPERATE;
};

class Random : public Strategy {	// �������� ��������
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::COOPERATE;
};

class Change : public Strategy {	// ��������� ������ �������
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::COOPERATE;
};