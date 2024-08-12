#include <SFML/Graphics.hpp>
#include <vlc/vlc.h>

void *lock(void *data, void **pixels)
{
    sf::Texture *texture = static_cast<sf::Texture *>(data);
    *pixels = const_cast<sf::Uint8 *>(texture->getPixelsPtr());
    return NULL;
}

void unlock(void *data, void *id, void *const *pixels)
{
    // You could do additional processing here if needed
}

void display(void *data, void *id)
{
    // This function could be used to update the display
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Video Playback Example");

    sf::Texture videoTexture;
    videoTexture.create(800, 600); // Assume the video resolution is 800x600

    sf::Sprite videoSprite(videoTexture);

    // Initialize libVLC
    libvlc_instance_t *vlcInstance = libvlc_new(0, nullptr);
    libvlc_media_player_t *mediaPlayer = libvlc_media_player_new(vlcInstance);

    libvlc_media_t *media = libvlc_media_new_path(vlcInstance, "../home/taha-pc/Videos/Screencasts.mp4");
    libvlc_media_player_set_media(mediaPlayer, media);

    // Set up video output
    libvlc_video_set_callbacks(mediaPlayer, lock, unlock, display, &videoTexture);
    libvlc_video_set_format(mediaPlayer, "RGBA", 800, 600, 800 * 4);

    libvlc_media_player_play(mediaPlayer);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(videoSprite);
        window.display();
    }

    // Clean up
    libvlc_media_player_stop(mediaPlayer);
    libvlc_media_player_release(mediaPlayer);
    libvlc_release(vlcInstance);

    return 0;
}
