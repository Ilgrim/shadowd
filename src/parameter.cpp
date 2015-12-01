/**
 * Shadow Daemon -- Web Application Firewall
 *
 *   Copyright (C) 2014-2015 Hendrik Buchwald <hb@zecure.org>
 *
 * This file is part of Shadow Daemon. Shadow Daemon is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, version 2.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */

#include "parameter.h"

void swd::parameter::set_path(std::string path) {
	path_ = path;
}

std::string swd::parameter::get_path() {
	return path_;
}

void swd::parameter::set_value(std::string value) {
	value_ = value;
}

std::string swd::parameter::get_value() {
	return value_;
}

int swd::parameter::get_length() {
	return value_.length();
}

void swd::parameter::add_blacklist_filter(swd::blacklist_filter_ptr filter) {
	blacklist_filters_.push_back(filter);
}

const swd::blacklist_filters& swd::parameter::get_blacklist_filters() {
	return blacklist_filters_;
}

void swd::parameter::add_whitelist_rule(swd::whitelist_rule_ptr rule) {
	whitelist_rules_.push_back(rule);
}

const swd::whitelist_rules& swd::parameter::get_whitelist_rules() {
	return whitelist_rules_;
}

int swd::parameter::get_impact() {
	int impact = 0;

	for (swd::blacklist_filters::iterator it_filter = blacklist_filters_.begin();
	 it_filter != blacklist_filters_.end(); it_filter++) {
		impact += (*it_filter)->get_impact();
	}

	return impact;
}

void swd::parameter::is_threat(bool threat) {
	threat_ = threat;
}

bool swd::parameter::is_threat() {
	return threat_;
}

void swd::parameter::has_critical_impact(bool critical) {
	critical_impact_ = critical;
}

bool swd::parameter::has_critical_impact() {
	return critical_impact_;
}

void swd::parameter::set_total_whitelist_rules(int total_whitelist_rules) {
	total_whitelist_rules_ = total_whitelist_rules;
}

int swd::parameter::get_total_whitelist_rules() {
	return total_whitelist_rules_;
}
