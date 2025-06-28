import java.util.*;

public class CloudStorageSystem {

    private static class FileEntry {
        String name;
        int size;

        FileEntry(String name, int size) {
            this.name = name;
            this.size = size;
        }
    }

    private static class TrieNode {
        Map<Character, TrieNode> children = new HashMap<>();
        Set<String> fileNames = new HashSet<>();
    }

    private Map<String, Integer> fileSystem = new HashMap<>();
    private TrieNode prefixRoot = new TrieNode();
    private TrieNode suffixRoot = new TrieNode();

    public boolean addFile(String name, int size) {
        if (fileSystem.containsKey(name)) return false;
        fileSystem.put(name, size);
        insertToTrie(prefixRoot, name, name, false);
        insertToTrie(suffixRoot, name, name, true);
        return true;
    }

    public boolean copyFile(String nameFrom, String nameTo) {
        if (!fileSystem.containsKey(nameFrom) || fileSystem.containsKey(nameTo)) {
            return false;
        }
        int size = fileSystem.get(nameFrom);
        fileSystem.put(nameTo, size);
        insertToTrie(prefixRoot, nameTo, nameTo, false);
        insertToTrie(suffixRoot, nameTo, nameTo, true);
        return true;
    }

    public Optional<Integer> getFileSize(String name) {
        return Optional.ofNullable(fileSystem.get(name));
    }

    public List<String> findFile(String prefix, String suffix) {
        Set<String> prefixMatches = searchTrie(prefixRoot, prefix, false);
        Set<String> suffixMatches = searchTrie(suffixRoot, suffix, true);

        // 取交集
        List<FileEntry> matchedFiles = new ArrayList<>();
        for (String name : prefixMatches) {
            if (suffixMatches.contains(name)) {
                matchedFiles.add(new FileEntry(name, fileSystem.get(name)));
            }
        }

        // 排序
        matchedFiles.sort((a, b) -> {
            if (a.size != b.size) {
                return Integer.compare(b.size, a.size); // 降序
            }
            return a.name.compareTo(b.name); // 字典序升序
        });

        List<String> result = new ArrayList<>();
        for (FileEntry file : matchedFiles) {
            result.add(file.name + "(" + file.size + ")");
        }
        return result;
    }

    // 插入到前缀树或后缀树
    private void insertToTrie(TrieNode root, String word, String fullPath, boolean reverse) {
        TrieNode node = root;
        String w = reverse ? new StringBuilder(word).reverse().toString() : word;

        for (char ch : w.toCharArray()) {
            node = node.children.computeIfAbsent(ch, k -> new TrieNode());
            node.fileNames.add(fullPath);
        }
    }

    // 查询匹配的文件集合
    private Set<String> searchTrie(TrieNode root, String query, boolean reverse) {
        TrieNode node = root;
        String q = reverse ? new StringBuilder(query).reverse().toString() : query;

        for (char ch : q.toCharArray()) {
            if (!node.children.containsKey(ch)) return Collections.emptySet();
            node = node.children.get(ch);
        }
        return node.fileNames;
    }
}