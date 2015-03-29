var
  i,j,L,n:longint;
  long,f:array[0..100] of longint;
  word:array[1..100] of string;
  s:string;
begin
  fillchar(f,sizeof(f),127);
  f[0]:=0;
  readln(s);L:=length(s);
  readln(n);
  for i:=1 to n do begin readln(word[i]);long[i]:=length(word[i]);end;
  for i:=1 to L do
    for j:=n downto 1 do
      if i>=long[j] then
        if copy(s,i-long[j]+1,long[j])=word[j] then
          if f[i-long[j]]+1<f[i] then
            f[i]:=f[i-long[j]]+1;
  writeln(f[L]);
end.
