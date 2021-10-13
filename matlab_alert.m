channelID = 276330;

% Provide the ThingSpeak alerts API key.  All alerts API keys start with TAK.
alertApiKey = 'TAK3X2YFG4R70PG769DGG';

% Set the address for the HTTTP call
alertUrl="https://api.thingspeak.com/alerts/send";

% webwrite uses weboptions to add required headers.  Alerts needs a ThingSpeak-Alerts-API-Key header.
options = weboptions("HeaderFields", ["ThingSpeak-Alerts-API-Key", alertApiKey ]);

% Set the email subject.
alertSubject = sprintf("High covid cases in Kerala");

% Read the recent data.
Data = thingSpeakRead(channelID,'NumDays',30,'Fields',1);


% Get the most recent point in the array of moisture data.
lastValue = Data(end); 

% Set the outgoing message
if (lastValue<=9000)
    alertBody = 'Please maintain social distance and wear masks. Turn on Social distance detector';
end
 
 % Catch errors so the MATLAB code does not disable a TimeControl if it fails
try
    webwrite(alertUrl , "body", alertBody, "subject", alertSubject, options);
catch someException
    fprintf("Failed to send alert: %s\n", someException.message);
end
