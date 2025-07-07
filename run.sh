#!/bin/bash
set -e

# Configuration
OP_REPO="https://github.com/commaai/openpilot.git"
OP_BRANCH="nightly-dev"
OP_DIR="tmp/openpilot"
OP_PATCH_BRANCH="op-nightly-dev"

SP_REPO="https://github.com/sunnypilot/sunnypilot.git"
SP_BRANCH="staging-c3-new"
SP_DIR="tmp/sunnypilot"
SP_PATCH_BRANCH="sp-staging-c3-new"

# Clean up previous run
rm -rf tmp
mkdir -p tmp

# Clone Repositories
echo "Cloning repositories..."
git clone --depth=1 --branch="$OP_BRANCH" "$OP_REPO" "$OP_DIR"
git clone --depth=1 --branch="$SP_BRANCH" "$SP_REPO" "$SP_DIR"

# Apply Patches
echo "Applying patches..."
sed -i 's/LOW_SPEED_LOCKOUT = 2/LOW_SPEED_LOCKOUT = False/g' "$OP_DIR/selfdrive/car/toyota/values.py"
echo 'export FINGERPRINT="TOYOTA COROLLA TSS2"' >> "$OP_DIR/launch_env.sh"
echo "Patched openpilot."

# For sunnypilot, we apply the same patches
sed -i 's/LOW_SPEED_LOCKOUT = 2/LOW_SPEED_LOCKOUT = False/g' "$SP_DIR/selfdrive/car/toyota/values.py"
echo 'export FINGERPRINT="TOYOTA COROLLA TSS2"' >> "$SP_DIR/launch_env.sh"
echo "Patched sunnypilot."


# Commit and Push Changes
echo "Committing and pushing changes..."

# openpilot
cd "$OP_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git add .
git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$OP_PATCH_BRANCH" --force
cd -

# sunnypilot
cd "$SP_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git add .
git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$SP_PATCH_BRANCH" --force
cd -

echo "Script finished."