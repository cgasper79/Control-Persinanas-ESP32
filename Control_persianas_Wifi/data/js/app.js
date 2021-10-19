Vue.use(VueNativeSock.default, 'ws://' + location.hostname + '/ws', { format: 'json' })


Vue.component('action', {
  props: ['action'],
  template: `
        <v-list-tile avatar>
        <v-list-tile-content>
          <v-list-tile-title>{{action.text}}</v-list-tile-title>
        </v-list-tile-content>
      <v-list-tile-action>
      <v-btn text small color="flat" @click="doAction">Ejecutar</v-btn>
      </v-list-tile-action>
      </v-list-tile>
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

var app = new Vue({
  el: '#app',
  data: function () {
    return {
      action_list1: [
        { id: 0, text: 'Subir', callback: () => console.log("Subir1") },
        { id: 1, text: 'Bajar', callback: () => console.log("Bajar1") },
        { id: 2, text: 'Stop', callback: () => console.log("Stop1") },
      ],
      action_list2: [
        { id: 3, text: 'Subir', callback: () => console.log("Subir2") },
        { id: 4, text: 'Bajar', callback: () => console.log("Bajar2") },
        { id: 5, text: 'Stop', callback: () => console.log("Stop2") },
      ]
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
