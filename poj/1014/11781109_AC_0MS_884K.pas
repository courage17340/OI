var
  a:array[1..6] of longint;
  v:array[0..1000] of boolean;
  n,i,j,k,s:longint;
begin
  n:=0;
  while true do
    begin
      inc(n);
      for i:=1 to 6 do read(a[i]);readln;
      s:=0;
      for i:=1 to 6 do s:=s+a[i]*i;
      if s=0 then break;
      if n<>1 then writeln;
      writeln('Collection #',n,':');
      if odd(s) then
        begin
          writeln('Can''t be divided.');
          continue;
        end;
      for i:=1 to 6 do a[i]:=a[i] mod 30;
      s:=0;       
      for i:=1 to 6 do s:=s+a[i]*i;
      fillchar(v,sizeof(v),false);
      v[0]:=true;
      for i:=1 to 6 do
        for j:=1 to a[i] do
          for k:=s shr 1 downto i do
            v[k]:=v[k] or v[k-i];
      if v[s shr 1]
        then writeln('Can be divided.')
        else writeln('Can''t be divided.');
    end;
end.