# OpenHiggsfield Delivery Plan

The product direction is now **offline-first, open-source, and cloud-optional**. The default app must not require a hosted backend, paid API, account, or internet connection for its core workflow. See [OFFLINE_FIRST_ARCHITECTURE.md](OFFLINE_FIRST_ARCHITECTURE.md).

## Phase 1 — Stable Android foundation
- [x] Package the Story Studio web build into Android assets.
- [x] Add a standalone debug APK workflow without Play Store credentials.
- [x] Fix Gradle property resolution discovered in CI.
- [ ] Produce and verify a clean debug APK.
- [ ] Smoke-test on a physical Android device.

## Phase 2 — Offline-first Android app
- [ ] Remove mandatory account and provider-key gates from the default app.
- [ ] Implement Android photo picker and safe local media access.
- [ ] Implement native MediaCodec/MediaMuxer still-image-to-MP4 rendering with motion presets.
- [ ] Add local project save/load, render progress/cancel, preview and share.
- [ ] Pass airplane-mode tests with zero outbound network requests.

## Phase 3 — Local AI inference (optional)
- [ ] Add a private-LAN/localhost ComfyUI connector; no hosted endpoints by default.
- [ ] Add pairing, local-only endpoint validation, job submission/polling and result transfer.
- [ ] Select Wan 2.2 or a smaller compatible open model only after checking device/workstation hardware and model license.
- [ ] Verify a real end-to-end run against a user's own local ComfyUI installation.
- [ ] Keep app fully usable when no local AI workstation is available.

## Phase 4 — Quality and release
- [ ] Add unit, UI, native-renderer and offline integration tests.
- [ ] Run APK build, install, export and media playback checks.
- [ ] Review dependency licenses, permissions, privacy, and security.
- [ ] Prepare signed AAB and Play Store configuration only when requested.

## Explicit non-goals
- No mandatory Render/Railway/Vercel backend.
- No fal, Higgsfield, OpenRouter, or other paid provider in the default path.
- No cloud storage, hosted database, analytics, telemetry, or compulsory sign-in.
- No claim that a motion preset is generative AI.
- No claim that a 4 GB phone can run a large video diffusion model locally.

## Hardware constraint
Open-source weights do not eliminate inference compute. The 4 GB Android target can run the offline motion renderer; large video diffusion models require a suitable local GPU workstation. The app must explain this and must never silently upload user media to a cloud provider.
