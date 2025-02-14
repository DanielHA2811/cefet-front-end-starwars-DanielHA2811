$(document).ready(function ()) {
    $.ajax({
        url: "https://swapi.dev/api/films/",
        type: "GET",
        dataType: "json",
        success: function (response) {
            let filmes = response.results;
            filmes.sort((a, b) => a.episode_id - b.episode_id);
            let filmesLista = $("#filmes ul");
            filmesLista.empty();
            filmes.forEach(filme => {
                let item = $("<li>").text(`Episode ${filme.episode_id}: ${filme.title}`).attr("data-id-episode", filme.episode_id).click(() => introducao(filme));
                filmesLista.append(item);
            });
        },
    });
    function introducao(filme) {
        $("#intro").text(`Episode ${filme.episode_id}\n${filme.title.toUpperCase()}\n${filme.opening_crawl}`);
    }
};
//meu deus