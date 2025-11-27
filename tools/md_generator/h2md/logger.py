#!/usr/bin/env python3

# If not stated otherwise in this file or this component's LICENSE file the
# following copyright and licenses apply:

# Copyright 2024 RDK Management

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

# http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# logger.py
import os
class Logger:
    """
    A simple logger class to log messages to a file.
    It categorizes messages into warnings, errors, and info.
    """
    def __init__(self, log_file_path):
        """
        Initializes the logger with a log file path.

        Args:
            log_file_path (str): Path to the log file.
        """
        self.log_file_path = log_file_path
        log_dir = os.path.dirname(log_file_path)
        os.makedirs(log_dir, exist_ok=True)
        self.log_file = open(log_file_path, 'w', encoding='utf-8')
        self.warning_msgs = []
        self.error_msgs = []
        self.info_msgs = []

    def log(self, level, message):
        """
        Logs a message with a specific level.

        Args:
            level (str): The log level (e.g., "WARNING", "ERROR", "INFO").
            message (str): The message to log.
        """
        if level == "WARNING":
            self.warning_msgs.append(message)
        elif level == "ERROR":
            self.error_msgs.append(message)
        elif level == "INFO":
            self.info_msgs.append(message)

    def write_log(self):
        """
        Writes the logged messages to the log file.
        """
        self.log_file.write("### Warnings\n")
        for msg in self.warning_msgs:
            self.log_file.write(f"- {msg}\n")
        self.log_file.write("\n### Errors\n")
        for msg in self.error_msgs:
            self.log_file.write(f"- {msg}\n")
        self.log_file.write("\n### Info\n")
        for msg in self.info_msgs:
            self.log_file.write(f"- {msg}\n")
        self.log_file.write("\n")
        self.log_file.write("### End of Log\n")

    def close(self):
        """
        Closes the log file.
        """
        self.log_file.close()
