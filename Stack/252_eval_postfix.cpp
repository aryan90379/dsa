import {
  View,
  Text,
  StyleSheet,
  TouchableOpacity,
  ScrollView,
  Platform,
  StatusBar,
  Image,
} from 'react-native';

import {
  Info,
  Shield,
  ChevronRight,
  ChevronLeft,
} from 'lucide-react-native';

import TermsOfServiceScreen from './TermsOfServiceScreen';

// --------------------------------------------------
// ASSETS
// --------------------------------------------------

const APP_LOGO = require('../assets/logo.png');

{/* Logo */}

<View
  style={
    styles.logoWrap
  }
>
  <Image
    source={APP_LOGO}
    resizeMode="contain"
    style={styles.logoImage}
  />
</View>

const styles = StyleSheet.create({
  logoWrap: {
    width: 84,
    height: 84,

    borderRadius: 28,

    backgroundColor:
      '#F5F3FF',

    borderWidth: 1,

    borderColor:
      '#ECE8FF',

    alignItems: 'center',

    justifyContent:
      'center',
  },

  logoImage: {
    width: 52,
    height: 52,
  },

  // ... rest of the styles
});
