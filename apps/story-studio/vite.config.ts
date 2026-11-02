import path from "node:path"
import tailwindcss from "@tailwindcss/vite"
import react from "@vitejs/plugin-react"
import { defineConfig } from "vite"

export default defineConfig({
  // Android WebView loads the built app from file:///android_asset; keep bundles relative.
  base: "./",
  plugins: [react(), tailwindcss()],
  resolve: { alias: { "@": path.resolve(__dirname, "./src") } },
  server: { port: 5193, proxy: { '/api': {target:'http://127.0.0.1:5194',changeOrigin:false} } },
})
