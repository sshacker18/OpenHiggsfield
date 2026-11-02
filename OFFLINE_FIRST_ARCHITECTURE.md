# OpenHiggsfield — Offline-First Product Architecture

## Product decision

OpenHiggsfield is a local-first creative studio. It must not require a hosted backend, account, subscription, API key, analytics service, or internet connection for its core editing and export workflow.

The Android app is the primary product. A user's own computer may optionally provide local AI inference over the private LAN; it is not a cloud dependency and must never be required to open or use the app.

## Non-negotiable requirements

- Core editing and video export work in airplane mode after installation.
- No fal, Higgsfield, OpenRouter, or other paid API dependency in the default path.
- No mandatory login, remote database, telemetry, or cloud storage.
- Images, projects, renders, and model files remain on the user's device or explicitly selected local machine.
- Open model weights are downloaded only by explicit user choice; show size, license, and hardware requirements before download.
- Do not describe template animation as generative AI. Label it honestly as offline motion design.
- Optional local AI inference must use a documented open protocol and connect only to a user-owned machine on the local network or localhost.

## Device reality and supported modes

### Mode A — Offline Motion Studio (must work on supported Android phones)

A deterministic, fully offline renderer that turns still images into MP4 clips using:
- Ken Burns pan/zoom, crop and camera paths
- Parallax layers where the user supplies or creates masks
- Timeline, transitions, titles, subtitles, and local audio
- Frame-rate, aspect-ratio, and duration controls
- Android MediaCodec + MediaMuxer hardware encoding
- Local project save/load and share/export

This mode is useful without a GPU or model download. It is not marketed as diffusion-based image-to-video generation.

### Mode B — Local AI Studio (optional, no cloud)

An optional adapter for ComfyUI running on the user's own Windows/Linux/macOS computer. The Android app discovers or accepts a LAN address, validates that the endpoint is private/local, uploads selected assets only to that machine, submits a workflow, polls progress, and downloads the result.

Initial workflow target: an open image-to-video workflow supported by ComfyUI (Wan 2.2 or a smaller compatible model selected after hardware profiling). Model licenses and exact hardware requirements must be checked before bundling or recommending weights.

No remote hosted ComfyUI or cloud inference is used by default.

## Hardware honesty

A 4 GB RAM Android phone is not a realistic target for running a large video diffusion model such as Wan 2.2 locally. It can still run the offline motion renderer and act as a controller for a locally owned GPU workstation. If no capable local GPU exists, the app remains useful in Offline Motion Studio mode; it must not silently fall back to paid cloud APIs.

## Security and privacy

- Bind any local companion service to loopback/LAN only; never expose it to the public internet by default.
- Require explicit pairing and a per-session token for LAN connections.
- No hard-coded credentials, analytics, remote crash reporting, or automatic uploads.
- Provide a clear local data directory and delete/export controls.
- Validate image/video MIME types, dimensions, sizes, and paths.

## Delivery sequence

1. Remove paid-provider requirements from the default app flow and make the app open without a key or account.
2. Implement the native offline still-image-to-MP4 renderer and expose it through a narrow Android WebView bridge.
3. Build project persistence, media import, progress/cancel, and output sharing.
4. Add automated offline tests and run airplane-mode smoke tests.
5. Add the optional local ComfyUI adapter and publish reproducible setup instructions for a user's own computer.
6. Keep all cloud/paid integrations out of the default build; if retained as experimental adapters, they must be disabled and clearly labelled.

## Acceptance criteria

- App launches and navigates in airplane mode.
- User can select a photo, choose a motion preset, render a video, preview it, and save/share it with no account, key, or network.
- Network inspection during the offline workflow shows no outbound requests.
- A clean build produces an installable APK.
- Optional AI mode is only marked supported after a real end-to-end run against a locally hosted ComfyUI instance.
