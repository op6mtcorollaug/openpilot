# openpilot and forks for 6MT TSS2 Corollas

![Shifter](https://github.com/user-attachments/assets/a7f471e8-0e70-4f9c-aac2-6d69815745ab)

[Image from Hooniverse](https://www.hooniverse.com/2020-toyota-corolla-is-all-about-savethemanuals-but-will-you-buy-it/)

This is an automated repository that patches comma.ai openpilot's `nightly-dev` and sunnypilot's `staging-c3-new` branches to support the 6MT TSS2 Corollas.

Efforts to upstream support for the 6MT TSS2 Corollas have stalled with a principal developer of the Corolla 6MT TSS2 unable to [contribute additional time for upstreaming](https://discord.com/channels/469524606043160576/1391211035796439163/1391232320790331472).

Discussion about this repository can be found in the [comma.ai openpilot Discord](https://discord.comma.ai) in the [2020-2022 6MT Corolla Thread underneath #toyota-lexus](https://discord.com/channels/469524606043160576/1391211035796439163)

## How it Works

A GitHub Actions workflow runs on a daily schedule to:

1.  Clone the latest versions of openpilot and sunnypilot.
2.  Apply the necessary patches from the `/patches` directory.
3.  Force-push the patched code to the `op-nightly-dev` and `sp-staging-c3-new` branches in this repository.

## Usage

You will install a patched version of openpilot or sunnypilot on your comma three device from this repository.

1. Reset the comma three device.
2. Choose `Custom Software` when installing the software.
3. In the text field, enter the following:
   * comma.ai openpilot:
     * `op6mtcorollaug/op-nightly-dev`
   * Sunnypilot: `
     * `op6mtcorollaug/sp-staging-c3-new`
4. That's it, you're done! The device will install the patched version of openpilot or sunnypilot.

### Later Usage

* This repository can and might break. Please discuss the issue in the thread linked above.
* This repository may become obsolete as upstream support is added to openpilot or sunnypilot. Please check the thread linked above for updates.