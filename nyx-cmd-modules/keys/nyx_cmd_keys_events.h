// Copyright (c) 2016-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef __NYXCMDKEYSEVENTS_H__
#define __NYXCMDKEYSEVENTS_H__

/**
 * @file nyx_cmd_keys_events.h
 *
 * @brief Implementation class for nyx-cmd Keys command.
 *
 */

#include <nyx/nyx_client.h>
#include <nyx/common/nyx_device.h>
#include <string>
class NyxCmdKeysEvents : public NyxCmdCommand
{
private:

	nyx_device_handle_t mDevice;
	nyx_device_type_t mDeviceType;
	void waitForEvent();
	void readKeyData();
	std::string keyToString(int key, nyx_key_type_t keyType);
public:
	/**
	 * Class constructor.
	 *
	 */
	NyxCmdKeysEvents(nyx_device_type_t deviceType);
	/**
	 * Get the description of the command functionality.
	 *
	 * @return String containing description of the functionality.
	 *
	 */
	std::string Description();

	/**
	 * Get the name for command. This will be compared against the command line arguments
	 *
	 * @return String containing command name.
	 *
	 */
	std::string Name();

	/**
	 * Execute the command. Full argument list is expected.
	 *
	 * @param[in]   deviceId - device identifier
	 * @param[in]   argc     - number of arguments
	 * @param[in]   argv     - list of arguments
	 *
	 * @return error value from command. 0 if no error.
	 *
	 */
	int Execute(const char *deviceId, int argc, char **argv);
};

#endif // __NYXCMDKEYSEVENTS_H__
