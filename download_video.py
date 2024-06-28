import sys
import time
from pytube import YouTube
from moviepy.editor import VideoFileClip, AudioFileClip, concatenate_videoclips
import os

def download_video(url, output_path):
    max_retries = 3
    retry_delay = 5  # seconds

    for attempt in range(max_retries):
        try:
            yt = YouTube(url)

            # Get the highest resolution video stream and audio stream
            video_stream = yt.streams.filter(adaptive=True, file_extension='mp4').order_by('resolution').desc().first()
            audio_stream = yt.streams.filter(only_audio=True, file_extension='mp4').first()

            # Download video and audio streams separately
            video_path = video_stream.download(filename='video_temp.mp4')
            audio_path = audio_stream.download(filename='audio_temp.mp4')

            # Load video and audio files
            video_clip = VideoFileClip(video_path)
            audio_clip = AudioFileClip(audio_path)

            # Set the audio to the video clip
            final_clip = video_clip.set_audio(audio_clip)

            # Write the final output to the specified path
            final_clip.write_videofile(output_path, codec='libx264')

            # Close the clips
            video_clip.close()
            audio_clip.close()

            # Clean up temporary files
            os.remove(video_path)
            os.remove(audio_path)

            print("Video downloaded successfully.")
            return
        except Exception as e:
            print(f"Attempt {attempt + 1} failed: {e}")
            if attempt < max_retries - 1:
                print(f"Retrying in {retry_delay} seconds...")
                time.sleep(retry_delay)
            else:
                print("Failed to download the video after multiple attempts.")
                sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python download_video.py <URL> <output_path>")
        sys.exit(1)

    url = sys.argv[1]
    output_path = sys.argv[2]
    download_video(url, output_path)
