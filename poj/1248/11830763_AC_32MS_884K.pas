var
  a:array[1..12] of longint;
  f:array[1..26,1..5] of longint;
  n,i,j,k,p,q,r,s,t:longint;
  ss:string;
  flag:boolean;
begin
  for i:=1 to 26 do f[i,1]:=i;
  for i:=2 to 5 do
    for j:=1 to 26 do
      f[j,i]:=f[j,i-1]*j;
  while true do
    begin
      read(n);
      if n=0 then break;
      readln(ss);
      j:=0;
      for i:=1 to length(ss) do
        if ss[i] in ['A'..'Z'] then
          begin
            inc(j);
            a[j]:=ord(ss[i])-64;
          end;
      k:=j;
      for i:=1 to k-1 do
        for j:=i+1 to k do
          if a[i]<a[j] then
            begin
              t:=a[i];
              a[i]:=a[j];
              a[j]:=t;
            end;
      flag:=false;
      for p:=1 to k do if not flag then
        for q:=1 to k do if not flag then if p<>q then
          for r:=1 to k do if not flag then if (p<>r)and(q<>r) then
            for s:=1 to k do if not flag then if (p<>s)and(q<>s)and(r<>s) then
              for t:=1 to k do if (p<>t)and(q<>t)and(r<>t)and(s<>t) then
                if f[a[p],1]-f[a[q],2]+f[a[r],3]-f[a[s],4]+f[a[t],5]=n then
                  begin
                    flag:=true;
                    writeln(chr(a[p]+64),chr(a[q]+64),chr(a[r]+64),chr(a[s]+64),chr(a[t]+64));
                    break;
                  end;
      if not flag then writeln('no solution');
    end;
end.