var
  f:array[0..500,0..500] of longint;
  s,t:ansistring;
  i,j,l1,l2:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  while not eof do
    begin
      fillchar(f,sizeof(f),0);
      readln(s);
      for i:=1 to length(s) do if s[i] in [' ',#9,#10,#13] then
        begin
          t:=copy(s,1,i-1);
          delete(s,1,i);
          while s[1] in[' ',#9,#10,#13] do delete(s,1,1);
          break;
        end;
      l1:=length(s);
      l2:=length(t);
      for i:=1 to l1 do
        for j:=1 to l2 do
          begin
            f[i,j]:=max(f[i-1,j],f[i,j-1]);
            if s[i]=t[j] then
              f[i,j]:=max(f[i,j],f[i-1,j-1]+1);
          end;
      writeln(f[l1,l2]);
    end;
end.