#!/usr/bin/env bash

# Variables
url="https://discord.com/api/download?platform=linux&format=deb"
output_file="/tmp/discord.deb"
discord_command="discord"

# Download the latest Discord .deb file
sudo curl -L -o "$output_file" "$url"

# Check if the download was successful
if [ $? -ne 0 ]; then
  echo "Error: Failed to download the Discord .deb file."
  exit 1
fi

# Install the downloaded .deb file
install_output=$(sudo apt install -y "$output_file" 2>&1)

# Check if Discord was updated
if echo "$install_output" | grep -q "upgraded, 0 newly installed"; then
  echo "Discord was already up-to-date. No need to reopen."
else
  echo "Discord has been updated successfully! Reopening Discord..."
  # Reopen Discord
  nohup $discord_command > /dev/null 2>&1 &
fi

# Clean up the .deb file after installation
sudo rm -f "$output_file"

exit 0

