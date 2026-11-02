#include <jni.h>
#include <vulkan/vulkan.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_sshacker18_openhiggsfield_MainActivity_runVulkanProbe(JNIEnv* env, jclass) {
    uint32_t version = VK_API_VERSION_1_0;
    VkResult result = vkEnumerateInstanceVersion(&version);
    char report[160];
    snprintf(report, sizeof(report), "vkEnumerateInstanceVersion=%d; Vulkan=%u.%u.%u", (int)result, VK_VERSION_MAJOR(version), VK_VERSION_MINOR(version), VK_VERSION_PATCH(version));
    return env->NewStringUTF(report);
}
