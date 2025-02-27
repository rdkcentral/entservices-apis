/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"
 // @stubgen:include <com/IIteratorType.h>
namespace WPEFramework {
namespace Exchange {

/**
 * If a setting was owned by an other component prior to being migrated into UserSettings,
 * we require the ability to detect when this migration has completed.
 * The component which was the previous owner of a given setting has the responsibility
 * to always set the setting on UserSettings interface (During migration AND during first time install).
 * Until this is done the setting is not considered valid, meaning the the MigrationState will contain requiresMigration=true
 * All settings not requiring migration would immediately be valid.
 */

    /* @json 1.0.0 @text:keep */
    struct EXTERNAL IUserSettingsInspector : virtual public Core::IUnknown {
      enum { ID = ID_USER_SETTINGS_INSPECTOR };

      ~IUserSettingsInspector() override = default;

      enum SettingsKey : uint32_t {
          PREFERRED_AUDIO_LANGUAGES = 0 /* @text PREFERRED_AUDIO_LANGUAGES */ ,
          AUDIO_DESCRIPTION = 1 /* @text AUDIO_DESCRIPTION */,
          CAPTIONS = 2 /* @text CAPTIONS */,
         PREFERRED_CAPTIONS_LANGUAGES = 3 /* @text PREFERRED_CAPTIONS_LANGUAGES */,
          PREFERRED_CLOSED_CAPTION_SERVICE = 4 /* @text PREFERRED_CLOSED_CAPTION_SERVICE */,
          PRESENTATION_LANGUAGE = 5 /* @text PRESENTATION_LANGUAGE */,
          HIGH_CONTRAST = 6 /* @text HIGH_CONTRAST */,
         PIN_CONTROL = 7 /* @text PIN_CONTROL */,
          VIEWING_RESTRICTIONS = 8 /* @text VIEWING_RESTRICTIONS */,
          VIEWING_RESTRICTIONS_WINDOW = 9 /* @text VIEWING_RESTRICTIONS_WINDOW */,
          LIVE_WATERSHED = 10 /* @text LIVE_WATERSHED */,
          PLAYBACK_WATERSHED = 11 /* @text PLAYBACK_WATERSHED */,
          BLOCK_NOT_RATED_CONTENT = 12 /* @text BLOCK_NOT_RATED_CONTENT */,
          PIN_ON_PURCHASE = 13 /* @text PIN_ON_PURCHASE */,
          VOICE_GUIDANCE = 14 /* @text VOICE_GUIDANCE */,
          VOICE_GUIDANCE_RATE = 15 /* @text VOICE_GUIDANCE_RATE */,
          VOICE_GUIDANCE_HINTS = 16 /* @text VOICE_GUIDANCE_HINTS */
      };

      struct SettingsMigrationState {
          SettingsKey key /* @text key */ ;
          bool requiresMigration /* @text requiresMigration */;
      };

     using IUserSettingsMigrationStateIterator = RPC::IIteratorType<SettingsMigrationState, ID_USER_SETTINGS_MIGRATION_STATE_ITERATOR>;

        /** Get the migration state of the respective key */
        // @text getMigrationState
        // @brief Get the migration state of the respective key
        // @param key: one of UserSettingsKey
        // @param requiresMigration: true if migration is required, false otherwise.
      virtual Core::hresult GetMigrationState(const SettingsKey key, bool &requiresMigration/* @out */) const = 0;

        /** Get the migration state of all the defined keys */
       // @text getMigrationStates
        // @brief Get the migration state of all the defined keys
        // @param states: array of migration status.
      virtual Core::hresult GetMigrationStates(IUserSettingsMigrationStateIterator*& states /* @out */) const = 0;

    };

  // @json @text:keep
struct EXTERNAL IUserSettings : virtual public Core::IUnknown
{
    enum { ID = ID_USER_SETTINGS };

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown
    {
        enum { ID = ID_USER_SETTINGS_NOTIFICATION };

        // Constructor
        INotification() {};

        // Destructor
        virtual ~INotification() {};

        // copy constructor
        INotification & operator=(const INotification &) = delete;

        // @text onAudioDescriptionChanged
        // @brief The AudioDescription setting has changed.
        // @param enabled: audioDescription enabled or not
        virtual void OnAudioDescriptionChanged(const bool enabled) {};

        // @text onPreferredAudioLanguagesChanged
        // @brief The preferredLanguages setting has changed.
        // @param preferredLanguages: the changed preferredLanguages.
        virtual void OnPreferredAudioLanguagesChanged(const string& preferredLanguages /* @text preferredLanguages */) {};

        // @text onPresentationLanguageChanged
        // @brief The PresentationLanguages setting has changed.
        // @param presentationLanguage: the changed presentationLanguage.
        virtual void OnPresentationLanguageChanged(const string& presentationLanguage /* @text presentationLanguage */) {};

        // @text onCaptionsChanged
        // @brief The Captions setting has changed.
        // @param enabled: Captions enabled or not.
        virtual void OnCaptionsChanged(const bool enabled) {};

        // @text onPreferredCaptionsLanguagesChanged
        // @brief The PreferredCaptionsLanguages setting has changed.
        // @param preferredLanguages: the changed preferredLanguages.
        virtual void OnPreferredCaptionsLanguagesChanged(const string& preferredLanguages /* @text preferredLanguages */) {};

        // @text onPreferredClosedCaptionServiceChanged
        // @brief The PreferredClosedCaptionService setting has changed.Eg: "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]".
        // @param service: the changed preferredClosedCaptionService.
        virtual void OnPreferredClosedCaptionServiceChanged(const string& service) {};

        // @alt onPinControlChanged
        // @brief The PinControl setting has changed.
        // @param pinControl: pinControl enabled or not.
        virtual void OnPinControlChanged(const bool pinControl) {};

        // @text onViewingRestrictionsChanged
        // @brief The ViewingRestrictions setting has changed.
        // @param viewingRestrictions: the changed viewingRestrictions.
        virtual void OnViewingRestrictionsChanged(const string& viewingRestrictions /* @text viewingRestrictions */) {};

        // @text onViewingRestrictionsWindowChanged
        // @brief The ViewingRestrictionsWindow setting has changed.
        // @param viewingRestrictionsWindow: the changed viewingRestrictionsWindow.
        virtual void OnViewingRestrictionsWindowChanged(const string& viewingRestrictionsWindow /* @text viewingRestrictionsWindow */) {};

        // @text onLiveWatershedChanged
        // @brief The LiveWatershed setting has changed.
        // @param liveWatershed: liveWatershed enabled or not.
        virtual void OnLiveWatershedChanged(const bool liveWatershed) {};

        // @text onPlaybackWatershedChanged
        // @brief The PlaybackWatershed setting has changed.
        // @param playbackWatershed: playbackWatershed enabled or not.
        virtual void OnPlaybackWatershedChanged(const bool playbackWatershed) {};

        // @text onBlockNotRatedContentChanged
        // @brief The BlockNotRatedContent setting has changed.
        // @param blockNotRatedContent: blockNotRatedContent enabled or not.
        virtual void OnBlockNotRatedContentChanged(const bool blockNotRatedContent) {};

        // @text onPinOnPurchaseChanged
        // @brief The PinOnPurchase setting has changed.
        // @param pinOnPurchase: pinOnPurchase enabled or not.
        virtual void OnPinOnPurchaseChanged(const bool pinOnPurchase) {};

        // @text onHighContrastChanged
        // @brief Triggered after the high contrast settings changes.
        // @param enabled: high contrast enabled or not.
        virtual void OnHighContrastChanged(const bool enabled) {};

        // @text onVoiceGuidanceChanged
        // @brief Triggered after the voice guidance enabled settings changes.
        // @param enabled: voice guidance enabled or not.
        virtual void OnVoiceGuidanceChanged(const bool enabled) {};

        // @text onVoiceGuidanceRateChanged
        // @brief Triggered after the voice guidance rate changed.
        // @param rate: the changed voice guidance rate.
        virtual void OnVoiceGuidanceRateChanged(const double rate) {};

        // @text onVoiceGuidanceHintsChanged
        // @brief Triggered after the voice guidance hints changes.
        // @param hints: voice guidance hints enabled or not.
        virtual void OnVoiceGuidanceHintsChanged(const bool hints) {};
    };

    virtual uint32_t Register(Exchange::IUserSettings::INotification* notification /* @in */) = 0;
    virtual uint32_t Unregister(Exchange::IUserSettings::INotification* notification /* @in */) = 0;

    // @text setAudioDescription
    // @brief Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled
    // @param enabled: Enabled/Disabled
    virtual uint32_t SetAudioDescription(const bool enabled /* @in */) = 0;

    // @text getAudioDescription
    // @brief Gets the current AudioDescription setting
    // @param enabled: Enabled/Disabled
    virtual uint32_t GetAudioDescription(bool &enabled /* @out */) const = 0;

    // @text setPreferredAudioLanguages
    // @brief A prioritized list of ISO 639-2/B codes for the preferred audio languages,
    // expressed as a comma separated lists of languages of zero of more elements.
    // The players will pick the audio track that has the best match compared with
    // this list. In the absence of a matching track, the player should by best
    // effort select the preferred audio track.*/
    // @param preferredLanguages: PreferredLanguages
    virtual uint32_t SetPreferredAudioLanguages(const string& preferredLanguages  /* @in @text preferredLanguages */) = 0;

    // @text getPreferredAudioLanguages
    // @brief Gets the current PreferredAudioLanguages setting
    // @param preferredLanguages: PreferredLanguages
    virtual uint32_t GetPreferredAudioLanguages(string &preferredLanguages /* @out @text preferredLanguages */) const = 0;

    // @text setPresentationLanguage
    // @brief Sets the presentationLanguage in a full BCP 47 value, including script, region, variant
    // @param presentationLanguage: "en-US", "es-US", "en-CA", "fr-CA"
    virtual uint32_t SetPresentationLanguage(const string& presentationLanguage /* @in @text presentationLanguage */) = 0;

    // @text getPresentationLanguage
    // @brief Gets the presentationLanguage
    // @param presentationLanguage: "en-US", "es-US", "en-CA", "fr-CA"
    virtual uint32_t GetPresentationLanguage(string &presentationLanguage /* @out @text presentationLanguage */) const = 0;

    // @text setCaptions
    // @brief brief Sets Captions ON/OFF.
    // @details A setting of ON indicates that Players should select a subtitle track for presentation
    // The Setting does not influence any running sessions. It is up to the player to enforce the setting.
    // This is a global state persisted by the TextTrack plug-in applying to all forms of text; closed captions, Captions
    // and timed text types.
    // Media players should to listen to OnCaptionsChanged notifications to react to platform wide dynamic state changes
    // of this state while a playback is active.
    // When media players start playback, they should also call the GetCaptions method to retrieve the current enabled state.
    // This holds true for media players that utilize TextTrack render sessions for text track decode-display and also for media
    // players or apps that decode-display internally 
    // @param enabled: Sets the state
    virtual uint32_t SetCaptions(const bool enabled  /* @in */) = 0;

    // @text getCaptions
    // @brief Gets the Captions setting.
    // @param enabled: Receives the state
    virtual uint32_t GetCaptions(bool &enabled /* @out */) const = 0;

    // @text setPreferredCaptionsLanguages
    // @brief Set preferred languages for captions.
    // @details A prioritized list of ISO 639-2/B codes for the preferred Captions languages,
    // expressed as a comma separated lists of languages of zero of more elements.
    // The players will pick the subtitle track that has the best match compared with
    // this list. In the absence of a matching track, the player should by best
    // effort select the preferred subtitle track. 
    // @param preferredLanguages: Is the list to set (e.g. "eng,fra")
    virtual uint32_t SetPreferredCaptionsLanguages(const string& preferredLanguages  /* @in @text preferredLanguages */) = 0;

    // @text getPreferredCaptionsLanguages
    // @brief Gets the current PreferredCaptionsLanguages setting.
    // @param preferredLanguages: "eng,fra"
    virtual uint32_t GetPreferredCaptionsLanguages(string &preferredLanguages /* @out @text preferredLanguages */) const = 0;

    // @text setPreferredClosedCaptionService
    // @brief Sets the PreferredClosedCaptionService.
    // @details The setting should be honored by the player. The behaviour of AUTO may be player specific.
    // Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]" 
    // @param service: Identifies the service to display e.g. "CC3".
    virtual uint32_t SetPreferredClosedCaptionService(const string& service  /* @in */) = 0;

    // @text getPreferredClosedCaptionService
    // @brief Gets the current PreferredClosedCaptionService setting.
    // @param service: Identifies the service to display e.g. "CC3".
    virtual uint32_t GetPreferredClosedCaptionService(string &service /* @out */) const = 0;

    // @alt setPinControl
    // @brief Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled.
    // @param pinControl: Enabled/Disabled
    virtual uint32_t SetPinControl(const bool pinControl /* @in */) = 0;

    // @text getPinControl
    // @brief Gets the PinControl setting
    // @param pinControl: Enabled/Disabled
    virtual uint32_t GetPinControl(bool &pinControl /* @out */) const = 0;

    // @text setViewingRestrictions
    // @brief Sets the ViewingRestrictions.
    // @details A JSON document that escribes the rating scheme(s) and ratings that are blocked.
    // @param viewingRestrictions: A JSON document that describes the rating scheme(s) and ratings that are blocked.
    virtual uint32_t SetViewingRestrictions(const string& viewingRestrictions /* @in @text viewingRestrictions */) = 0;

    // @text getViewingRestrictions
    // @brief Gets the current ViewingRestrictions.
    // @param viewingRestrictions: A JSON document that escribes the rating scheme(s) and ratings that are blocked.
    virtual uint32_t GetViewingRestrictions(string &viewingRestrictions /* @out @text viewingRestrictions */) const = 0;

    // @text setViewingRestrictionsWindow
    // @brief Sets the ViewingRestrictionsWindow.
    // @details A project-specific representation of the time interval when viewing
    // restrictions are to be applied, if applicable for the project
    // @param viewingRestrictionsWindow: A project-specific representation of the time interval.Eg: "ALWAYS"
    virtual uint32_t SetViewingRestrictionsWindow(const string &viewingRestrictionsWindow /* @in @text viewingRestrictionsWindow */) = 0;

    // @text getViewingRestrictionsWindow
    // @brief Gets the current ViewingRestrictionsWindow.
    // @param viewingRestrictionsWindow: A project-specific representation of the time interval.Eg: "ALWAYS"
    virtual uint32_t GetViewingRestrictionsWindow(string &viewingRestrictionsWindow /* @out @text viewingRestrictionsWindow */) const = 0;

    // @text setLiveWatershed
    // @brief Sets LiveWatershed ON/OFF.Whether project-specific watershed rules
    // should be applied for live content, if applicable for the project.
    // @param liveWatershed: Enabled/Disabled
    virtual uint32_t SetLiveWatershed(const bool liveWatershed /* @in */) = 0;

    // @text getLiveWatershed
    // @brief Gets the LiveWatershed setting
    // @param liveWatershed: Enabled/Disabled
    virtual uint32_t GetLiveWatershed(bool &liveWatershed /* @out */) const = 0;

    // @text setPlaybackWatershed
    // @brief Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules
    // should be applied for non-live content, if applicable for the project.
    // @param playbackWatershed: Enabled/Disabled
    virtual uint32_t SetPlaybackWatershed(const bool playbackWatershed /* @in */) = 0;

    // @text getPlaybackWatershed
    // @brief Gets the PlaybackWatershed setting
    // @param playbackWatershed: Enabled/Disabled
    virtual uint32_t GetPlaybackWatershed(bool &playbackWatershed /* @out */) const = 0;

    // @text setBlockNotRatedContent
    // @brief Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be
    // blocked, if applicable for the project.
    // @param blockNotRatedContent: Enabled/Disabled
    virtual uint32_t SetBlockNotRatedContent(const bool blockNotRatedContent /* @in */) = 0;

    // @text getBlockNotRatedContent
    // @brief Gets the BlockNotRatedContent setting
    // @param blockNotRatedContent: Enabled/Disabled
    virtual uint32_t GetBlockNotRatedContent(bool &blockNotRatedContent /* @out */) const = 0;

    // @text setPinOnPurchase
    // @brief Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made
    // when a purchase is attempted.
    // @param pinOnPurchase: Enabled/Disabled
    virtual uint32_t SetPinOnPurchase(const bool pinOnPurchase /* @in */) = 0;

    // @text getPinOnPurchase
    // @brief Gets the PinOnPurchase setting
    // @param pinOnPurchase: Enabled/Disabled
    virtual uint32_t GetPinOnPurchase(bool &pinOnPurchase /* @out */) const = 0;

    // @text setHighContrast
    // @brief Sets highContrast. Whether the app should display with high contrast or not.
    // @param enabled: Enabled/Disabled
    virtual uint32_t SetHighContrast(const bool enabled /* @in */) = 0;

    // @text getHighContrast
    // @brief Gets the current highContrast setting.
    // @param enabled: Enabled/Disabled
    virtual uint32_t GetHighContrast(bool &enabled /* @out */) const = 0;

    // @text setVoiceGuidance
    // @brief Sets voiceGuidance. Whether Voice Guidance is enabled or not.
    // @param enabled: Enabled/Disabled
    virtual uint32_t SetVoiceGuidance(const bool enabled /* @in */) = 0;

    // @text getVoiceGuidance
    // @brief Gets the current voiceGuidance setting.
    // @param enabled: Enabled/Disabled
    virtual uint32_t GetVoiceGuidance(bool &enabled /* @out */) const = 0;

    // @text setVoiceGuidanceRate
    // @brief Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive.
    // @param rate: Sets Voice Guidance rate
    virtual uint32_t SetVoiceGuidanceRate(const double rate /* @in */) = 0;

    // @text getVoiceGuidanceRate
    // @brief Gets the current voiceGuidanceRate setting.
    // @param rate: Gets Voice Guidance rate
    virtual uint32_t GetVoiceGuidanceRate(double &rate /* @out */) const = 0;

    // @text setVoiceGuidanceHints
    // @brief Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not.
    // @param hints: Enabled/Disabled
    virtual uint32_t SetVoiceGuidanceHints(const bool hints /* @in */) = 0;

    // @text getVoiceGuidanceHints
    // @brief Gets the current voiceGuidanceHints setting.
    // @param hints: true/false
    virtual uint32_t GetVoiceGuidanceHints(bool &hints /* @out */) const = 0;

};

} // namespace Exchange
} // namespace WPEFramework

