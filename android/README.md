# Android app

This native Android shell packages the Story Studio Vite build in a WebView. The web UI is built by the GitHub Actions workflow and copied into app/src/main/assets before Gradle runs.

- Debug APK: generated on every workflow run.
- Signed release APK: generated only when the repository has the Android signing secrets.
- Package: `com.sshacker18.openhiggsfield`.

The app requires a running OpenHiggsfield backend for authentication, generation, and media operations. The Android asset bundle alone does not host the server or provide AI inference. Configure a secure hosted service URL and API routing before distributing it outside local/demo use.
