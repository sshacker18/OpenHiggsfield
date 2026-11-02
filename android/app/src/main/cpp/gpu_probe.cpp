#include <jni.h>
#include <vulkan/vulkan.h>
#include <cstdio>

extern "C" JNIEXPORT jstring JNICALL
Java_com_sshacker18_openhiggsfield_MainActivity_runVulkanProbe(JNIEnv* env, jclass) {
    uint32_t version = VK_API_VERSION_1_0;
    auto enumerateVersion = reinterpret_cast<PFN_vkEnumerateInstanceVersion>(
        vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkEnumerateInstanceVersion")
    );

    VkResult result = VK_SUCCESS;
    if (enumerateVersion != nullptr) {
        result = enumerateVersion(&version);
    }

    char report[160];
    snprintf(report, sizeof(report),
             "vkEnumerateInstanceVersion=%d; Vulkan=%u.%u.%u; function=%s",
             static_cast<int>(result),
             VK_VERSION_MAJOR(version),
             VK_VERSION_MINOR(version),
             VK_VERSION_PATCH(version),
             enumerateVersion != nullptr ? "available" : "not available (Vulkan 1.0)");
    return env->NewStringUTF(report);
}
