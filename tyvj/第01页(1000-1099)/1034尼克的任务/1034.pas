var
  min,p,t:array[0..10001] of longint;
  n,k,i,j:longint;
begin
  readln(n,k);
  for i:=1 to k do readln(p[i],t[i]);
  j:=k;
  min[n+1]:=0;
  for i:=n downto 1 do
    begin
      min[i]:=0;
      if p[j]<>i then min[i]:=1+min[i+1]
        else while p[j]=i do
          begin
            if min[i+t[j]]>min[i] then min[i]:=min[i+t[j]];
            dec(j);
          end;
    end;
  writeln(min[1]);
end.