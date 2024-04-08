#include <cstdint> // for uintX_t(X is bit size) types

extern "C" void KernelMain(uint64_t frame_buffer_base, // pass the frame buffer's base address
                           uint64_t frame_buffer_size) { // and it's size from bootloader
    uint8_t* frame_buffer = reinterpret_cast<uint8_t*>(frame_buffer_base); // just a (uint8_t*) cast but more careful
    for(uint64_t i = 0; i < frame_buffer_size; ++i) {
        frame_buffer[i] = i % 256;
    }

    while(1) __asm__("hlt");
}
