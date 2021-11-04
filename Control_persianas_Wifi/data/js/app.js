Vue.use(VueNativeSock.default, 'ws://' + location.hostname + '/ws', { format: 'json' })


Vue.component('action', {
  props: ['action'],
  template: ` 
        <v-btn fab large color="#FF1744" @click="doAction">
        <v-icon>{{action.text}}</v-icon>
        </v-btn>    
      
`,
  methods: {
    doAction: function (evt) {
      console.log(this.action.text + ': ' + this.action.id);
      let data = {
        command: "doAction",
        id: this.action.id,
      }

      let json = JSON.stringify(data);
      this.$socket.send(json);

      this.action.callback();
    }
  }
})


Vue.component('gpio-output', {
  props: ['gpio'],
  template: ` 
    <v-list-tile avatar>
      <v-list-tile-content>
        <v-list-tile-title>{{gpio.text}}</v-list-tile-title>
      </v-list-tile-content>
      <v-list-tile-action>
        <v-switch v-model="gpio.status" class="ma-2" :label="gpio.status ? 'ON' : 'OFF'" @change="sendGPIO"></v-switch>
      </v-list-tile-action>
    </v-list-tile>
`,
  methods: {
    sendGPIO: function (evt) {
      console.log(this.gpio.id + ': ' + this.gpio.status);

      let data = {
        command: "setGPIO",
        id: this.gpio.id,
        status: this.gpio.status
      }
      
      let json = JSON.stringify(data);
      this.$socket.send(json);
    }
  }
})

var app = new Vue({
  el: '#app',
  data: function () {
    return {

      action_list1: [
        { id: 0, text: 'mdi-chevron-up-circle-outline', callback: () => console.log("Subir1") },
        { id: 2, text: 'mdi-circle-outline', callback: () => console.log("Stop1") },
        { id: 1, text: 'mdi-chevron-down-circle-outline', callback: () => console.log("Bajar1") },
      ],
      action_list2: [
        { id: 3, text: 'mdi-chevron-up-circle-outline', callback: () => console.log("Subir2") },
        { id: 5, text: 'mdi-circle-outline', callback: () => console.log("Stop2") },
        { id: 4, text: 'mdi-chevron-down-circle-outline', callback: () => console.log("Bajar2") },
      ],
      action_list3: [
        { id: 6, text: 'mdi-chevron-up-circle-outline', callback: () => console.log("SubirTodo") },
        { id: 8, text: 'mdi-circle-outline', callback: () => console.log("StopTodo") },
        { id: 7, text: 'mdi-chevron-down-circle-outline', callback: () => console.log("BajarTodo") },
      ],

      gpio_output_list: [
        { id: 9, text: 'Modo Automático Noche/dia', status: 0 },
        { id: 10, text: 'Mitad persiana', status: 0 },
      ],
    }
  },
  mounted() {
    this.$socket.onmessage = (dr) => {
      console.log(dr);
      let json = JSON.parse(dr.data);
      let gpio = this.$data.gpio_input_list.find(gpio => gpio.text == json.id);
      gpio.status = json.status;
    }
  }
})
