# OpenHiggsfield Delivery Plan

This plan tracks the work required to deliver an installable Android app with a working, hosted image-to-video workflow.

## Phase 1 — Android build and device smoke test
- [x] Package the Story Studio web build into Android assets.
- [x] Add a standalone debug APK workflow that does not require Play Store credentials.
- [x] Fix Gradle property resolution discovered in the first CI build.
- [ ] Produce and verify the debug APK artifact.
- [ ] Install on a physical Android device and smoke-test navigation, upload permissions, and media preview.

## Phase 2 — Android app connectivity
- [ ] Replace the file-only WebView runtime with a configurable HTTPS application origin.
- [ ] Keep a local offline shell for diagnostics, but route authenticated API traffic to the configured backend.
- [ ] Add safe Android file chooser handling for image uploads and camera/gallery selection.
- [ ] Verify session persistence, upload progress, downloads, and video playback on-device.

## Phase 3 — Backend deployment
- [ ] Select and document a persistent hosting target for the Node/SQLite backend.
- [ ] Deploy HTTPS, persistent storage, health checks, backups, and email sign-in.
- [ ] Configure app origin, authentication secret, allowed signup policy, and email delivery.
- [ ] Verify account/workspace isolation and encrypted provider credential storage in the deployed environment.

## Phase 4 — Image-to-video generation
- [ ] Preserve the existing fal and Higgsfield adapters.
- [ ] Add a ComfyUI-compatible adapter for a user-provided reachable ComfyUI endpoint and workflow.
- [ ] Define and validate the supported Wan workflow, model files, input image, prompt, output video, and job polling.
- [ ] Run a real end-to-end generation and verify clip assembly and download.

**Important:** Wan weights may be open source, but inference still requires an accessible GPU host. This repository cannot create free GPU capacity by itself. The Android phone is a client, not the inference machine.

## Phase 5 — QA, release, and Play Store
- [ ] Add deterministic backend/API and UI regression coverage; make CI fail on real test failures.
- [ ] Run Android debug and release builds, inspect package identity, permissions, and app behavior.
- [ ] Configure the upload keystore and Play Console service-account credentials as repository secrets.
- [ ] Publish an internal-testing AAB, validate installation/update behavior, then prepare production release.

## External inputs that cannot be fabricated
- A persistent backend hosting account/project and domain or service URL.
- For Wan/ComfyUI: a reachable GPU host, ComfyUI endpoint, and compatible workflow/model setup.
- For paid fal/Higgsfield: the user's provider API credentials and billing account.
- For Play Store: Play Console app registration and a service account authorized for this package.
